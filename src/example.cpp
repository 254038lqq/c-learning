#include <iostream>
#include <dirent.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <thread>
#include <zlib.h>
#include <opencv2/freetype.hpp>
#include <chrono>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn/dnn.hpp> // NOLINT
#include <jsoncpp/json/json.h>
#include "aidlux/smartvision/smart_vision.hpp"
#include <plog/Log.h> 
#include <plog/Initializers/RollingFileInitializer.h>


#include "example.hpp"
using namespace std;
using namespace Aidlux::SmartVision;


int PROP_BOX_SIZE;
int OBJ_CLASS_NUM;

string model_path;
int img_width;
int img_height;
int MODEL_h;
int MODEL_w;
int output_h;
int output_w;
int output_defect_len;

string class_names;
string output_nodes;

int stop_sign = 0;

#define IMG_WIDTH 1024
#define IMG_HEIGH 1024

cv::Mat frame;
DetectModel model;

bool data_sign = false;

std::string release_id;
std::string release_version;
Json::Value model_config;
Json::Value defect_config;
Json::Value custom_config;
string current_global_path;
string target_folder_path;

int defect_len;

int thread_count;
int isCamera;

string imgPath = "imgs";

void sigint_handler(int sig){
    if(sig == SIGINT)
    {
        cout << "ctrl+c pressed!" << endl;
        stop_sign = 1;
    }
}

bool directoryExists(const std::string& path) {
    struct stat info;
    return stat(path.c_str(), &info) == 0 && S_ISDIR(info.st_mode);
}

bool createDirectory(const std::string& path) {
    return mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) == 0;
}

cv::Mat SDKframe;
int8_t my_get_img_cb(const Aidlux::SmartVision::Image & cap_img, uint64_t index)
{
    //cout << "cap_img.w=" << cap_img.w << ", cap_img.h=" << cap_img.h << endl;

    // //先判断图像大小是否一致
    // if ((cap_img.w != IMG_WIDTH) || (cap_img.h != cap_img.h))
    // {
    //     //cout << "cap_img.w=" << cap_img.w << "cap_img.h=" << cap_img.h << endl;
    //     cout << "data error!" << index << ",cap_img.w=" << cap_img.w << ", expected=" << IMG_WIDTH << ",cap_img.h=" << cap_img.h << ", expected=" <<IMG_HEIGH<<endl;
    //     return 0;
    // }

    // //先判断数据长度是否一致
    if (cap_img.length != cap_img.w*cap_img.h*3)
    {
        cout << "image w=" << cap_img.w << ", h=" << cap_img.h << endl;
        cout << "data error! " << index << " data length=" << cap_img.length << ",but expected " << cap_img.w*cap_img.h*3<<endl;
        return 0;
    }

    // 添加处理程序，当data_sign为真才处理
    if(data_sign){
        cout << index << endl;
        cout << "image w=" << cap_img.w << ", h=" << cap_img.h << endl;


        //根据长宽，自适应, 高，宽
        cv::Mat imgbuf(cap_img.h, cap_img.w, CV_8UC3, (void*)cap_img.data);

		SDKframe = imgbuf.clone();

        // FILE* file = fopen("xxxrgbout.rgb", "wr");
        // fwrite(cap_img.data, cap_img.length, 1, file);
        // fclose(file);

        data_sign = false;
    }

    return 0;
}

int8_t open_camera_with_internal(Aidlux::SmartVision::Camera & camera, string & cfg_path)
{

    //Aidlux::SmartVision::openLog();
    //Aidlux::SmartVision::setLogDestination("./aidclog_smart_vision_");

    //Aidlux::SmartVision::DeviceParam dev_param;
    //dev_param.sn = "123456"; //设置sn
    //dev_param.dev_name = "/dev/video1"; //设置相机设备
    //dev_param.cfg_name = cfg_path.c_str(); //设置相机配置文件路径

    //注意软触发和IO触发都是依靠此cb来获取相机采图数据
    //if (0 > camera.open(dev_param,my_get_img_cb) ){
    if (0 > camera.open(my_get_img_cb) ){
        printf("opening the camera failed!\n");
        return -1;
    }

    //Aidlux::SmartVision::closeLog();
    printf("opened the camera successfully!\n");

    return 0;
}

void loadconfigfile(string & release_path, string & model_config_path, string & defect_config_path, string & custom_config_path)
{
    //////////////////////////////////////////////// Parse configuration file ////////////////////////////////////////////////
    bool parsingSuccessful;
    Json::Reader reader;


    Json::Value release_config;

    std::ifstream release_config_file(release_path);
    parsingSuccessful = reader.parse(release_config_file, release_config);

    if (!parsingSuccessful) {
        std::cout << "Failed to parse the release_config  file!" << std::endl;
    }else {
        std::cout << "Successfully parsed the configuration: release.txt" << std::endl;
        release_id = release_config["id"].asString();
        release_version = release_config["version"].asString();
        std::cout << "release_id:  " << release_id << "  release_version:  " << release_version << std::endl;
    }

    std::ifstream model_config_file(model_config_path);
    parsingSuccessful = reader.parse(model_config_file, model_config);

    if (!parsingSuccessful) {
        std::cout << "Failed to parse the model_config file!" << std::endl;
    }else {
        std::cout << "Successfully parsed the configuration: model.config" << std::endl;
        model_path = model_config[0]["path"].asString();
        model_path = "model/" + model_path;
        std::cout << "object_model_path:   " << model_path << std::endl;

        output_nodes = model_config[0]["out_nodes"].asString();
        std::cout << "output_nodes:   " << output_nodes << std::endl;

        MODEL_w = model_config[0]["size"][0].asInt();
        MODEL_h = model_config[0]["size"][1].asInt();
        std::cout << "MODEL_h:   " << MODEL_h << "MODEL_w:   " << MODEL_w << std::endl;

        const Json::Value& class_names_array = model_config[0]["class_names"];
        OBJ_CLASS_NUM = class_names_array.size();
        PROP_BOX_SIZE = OBJ_CLASS_NUM + 5;
        std::cout << "OBJ_CLASS_NUM:   " << OBJ_CLASS_NUM << std::endl;


        Json::Value& output_shape = model_config[0]["output_shape"];

        cout <<"output_shape=============================" << output_shape << endl;

        output_h = output_shape[0][1].asInt();
        output_w = output_shape[0][2].asInt();
        output_defect_len = output_shape[0][3].asInt();
    }

    std::ifstream defect_config_file(defect_config_path);
    parsingSuccessful = reader.parse(defect_config_file, defect_config);
    cout <<"defect_config.size()=============================" << defect_config.size() << endl;

    if (!parsingSuccessful) {
        std::cout << "Failed to parse the defect_config  file!" << std::endl;
    }else {
        std::cout << "Successfully parsed the configuration: defect.config" << std::endl;
    }

    std::ifstream custom_config_file(custom_config_path);
    parsingSuccessful = reader.parse(custom_config_file, custom_config);
    cout <<"custom_config.size()=============================" << custom_config.size() << endl;

    if (!parsingSuccessful) {
        std::cout << "Failed to parse the custom_config  file!" << std::endl;
    }else {
        thread_count = custom_config[0]["thread_count"].asInt();
        cout << "thread_count:=======" << thread_count << endl;

        isCamera = custom_config[0]["is_camera"].asInt();
        // 1 是使用相机取图，否则为静态读图
        std::cout << "isCamera:=======" << isCamera << std::endl;
        std::cout << "Successfully parsed the configuration: custom.config" << std::endl;
    }
}



//算法主要处理过程，依赖变量 frame(原始图像数据), mode(算法模型引擎)
int mainhandle(cv::Mat &frame, DetectModel &model)
{
    // 此处使用临时图片替代相机获取的数据
    // string img_path = "imgs/snapshot_20231220134705906.jpg";
    // frame = cv::imread(img_path);
    if(frame.empty()){
        cerr << "failed read frame" << endl;
        return -1;
    }     
	
	//确定一个文件存放目录，和线程挂钩，避免不同线程之间冲突
	int iThreadID = gettid();	
	cout << "mainhandle get tid " << iThreadID << endl;	
	char szDirPath[50];
	sprintf(szDirPath, "/tmp/%d", iThreadID);
    if (!directoryExists(szDirPath)) {  //
        createDirectory(szDirPath);
	}

	char szOriginPath[100];	sprintf(szOriginPath, "%s/origin.jpg", szDirPath);
    char szFinalPath[100];	sprintf(szFinalPath, "%s/final.jpg", szDirPath);
    char szMaskPath[100];	sprintf(szMaskPath, "%s/mask.jpg", szDirPath);	
	
    //cv::imwrite("origin.jpg", frame);
    cv::imwrite(szOriginPath, frame);

    img_width = frame.cols;
    img_height = frame.rows;
    cout << "origin_image_width_height:  " << img_width << "  " << img_height << endl;

///////////////////////////////////////////////////////////////// 预处理 ////////////////////////////////////////////////
    cv::Mat roi_img;
    cv::Mat input_data;	
	
    struct timeval pre; 
    gettimeofday(&pre, NULL); 
    time_t curpre = pre.tv_sec;
    struct tm *tpre = localtime(&curpre);
    int prestart = pre.tv_sec*1000 + pre.tv_usec/1000;
    cout <<tpre->tm_hour <<":"<<tpre->tm_min <<":"<<tpre->tm_sec<<" preprocessing start" << endl;

    const Json::Value& location_roi = model_config[0]["roi_param"];
    cout << "location_roi: ========" << location_roi << endl;
    if (location_roi.size() > 0) {
        cout << "enter location_roi" << endl;
        double roi1 = location_roi[0].asDouble();
        double roi2 = location_roi[1].asDouble();
        double roi3 = location_roi[2].asDouble();
        double roi4 = location_roi[3].asDouble();
        cout << "roi1_roi2_roi3_roi4: ========" << roi1 << " " << roi2 << " " << roi3 << " " << roi4 << endl;
        int x = int(img_width * roi1);
        int y = int(img_height * roi2);
        int w = int(img_width * roi3);
        int h = int(img_height * roi4);
        int roi_y = y + h;
        int roi_x = x + w;
        // 1024, 1024 => x: 9.5232; y: 11.1616; w: 1009.9712; h: 1000.96; roi_x: 1019.4944; roi_y: 1012.1216
        cout << "x_y_w_h_roiy_roix: ========" << x << " " << y << " " << w << " " << h << " " << roi_y << " " << roi_x << endl;
        //  cv::resize(frame, roi_img, cv::Size(1012, 1019));
        cv::resize(frame, roi_img, cv::Size(roi_y, roi_x));
        cout << "over location_roi" << endl;
    } else {
        // cv::resize(frame, roi_img, cv::Size(img_height, img_width));
        roi_img = frame;
        int roi_img_width = roi_img.cols;
        int roi_img_height = roi_img.rows;
        cout << "roi_img_width_height:  " << roi_img_width << "  " << roi_img_height << endl;
    }

    // cv::cvtColor(roi_img, roi_img, cv::COLOR_BGR2RGB);

    cv::Scalar stds_scale(58.395, 57.12, 57.375);
    cv::Scalar means_scale(123.675, 116.28, 103.53);

    cout << "resize roi img" << endl;
    cv::resize(roi_img, roi_img, cv::Size(MODEL_w, MODEL_h));

    roi_img.convertTo(input_data, CV_32F);
    cv::subtract(input_data, means_scale, input_data);
    cv::divide(input_data, stds_scale, input_data);

    gettimeofday(&pre, NULL); 
    curpre = pre.tv_sec; 
    tpre = localtime(&curpre); 
    int preend = pre.tv_sec*1000 + pre.tv_usec/1000;
    int pretime = preend-prestart;
    cout <<tpre->tm_hour <<":"<<tpre->tm_min <<":"<<tpre->tm_sec<<" preprocessing over,time consumed:" << pretime  << " ms" <<endl;

    PLOG_DEBUG << "preprocessing time: " << pretime;

    // 输出部分图像元素值（仅作为示例）
    // std::cout << "First 5 elements of the image:\n" << input_data.rowRange(155, 156).colRange(0, 5) << std::endl;

    int input_data_width = input_data.cols;
    int input_data_height = input_data.rows;
    int input_data_channels = input_data.channels();
    cout << "input_data_width_height_channels:  " << input_data_width << "  " << input_data_height << "  "<< input_data_channels << endl;

//////////////////////////////////////////////////////////////// invoke ////////////////////////////////////////////////

    struct timeval tv; gettimeofday(&tv, NULL); time_t cur = tv.tv_sec; struct tm *t = localtime(&cur); int mstartsec = tv.tv_sec*1000 + tv.tv_usec/1000;
    cout <<t->tm_hour <<":"<<t->tm_min <<":"<<t->tm_sec<<" invoke start" << endl;
	
	float* out_data = (float*)malloc(output_w * output_h * output_defect_len * sizeof(float));	
    model.run(&input_data, out_data);
	
    cout << "out_data: ===================end" << out_data << std::endl;
    gettimeofday(&tv, NULL); cur = tv.tv_sec; t = localtime(&cur); int mendtsec = tv.tv_sec*1000 + tv.tv_usec/1000;
    int invoketime = mendtsec-mstartsec;
    cout <<t->tm_hour <<":"<<t->tm_min <<":"<<t->tm_sec<<" invoke over,time consumed:" << invoketime  << " ms" <<endl;

    PLOG_DEBUG << "invoke time: " << invoketime;


///////////// ///////////////////////////////////////////////// 后处理 /////////////////////////////////////////////////
    struct timeval aft;
    gettimeofday(&aft, NULL);
    time_t curaft = aft.tv_sec;
    struct tm *taft = localtime(&curaft);
    int aftstart = aft.tv_sec*1000 + aft.tv_usec/1000;
    cout <<taft->tm_hour <<":"<<taft->tm_min <<":"<<taft->tm_sec<<" reprocessing start" << endl;

    cout << "output_w_h_defect_len:  " << output_w << "  " << output_h << "  "<< output_defect_len << endl;
    uint8_t *m_PositionOutput;
    m_PositionOutput = (uint8_t *)malloc(output_w * output_h*output_defect_len * sizeof(uint8_t));

    for (int i = 0; i < output_defect_len; i++) {

        int k = 0;
        for (int j = i; j < output_w * output_h*output_defect_len; j +=3)
        {
            if (out_data[j] > 0.5)
            {
                m_PositionOutput[k] = 255;
            }
            else
            {
                m_PositionOutput[k] = 0;
            }
            k += 1;
        }
        cv::Mat maskImg(output_h, output_w, CV_8U, m_PositionOutput);
        //cv::imwrite("mask-"+to_string(i)+".jpg", maskImg);
		
        string txt = defect_config[i]["key"].asString();
        cout << "txt:================" << txt << endl;
        if (txt == "paichu") {
            continue;
        }
        auto minLength = defect_config[i]["data"]["minLength"].asDouble();
        cout << "minLength:================" << minLength << endl;
        auto minArea = defect_config[i]["data"]["minArea"].asDouble();
        cout << "minArea:================" << minArea << endl;
        int color_step = int(255/output_defect_len);
        cout << "color_step:================" << color_step << endl;
        // auto defectColor = (0, (i + 1) * color_step, 255 - (i + 1) * color_step);
        int color1 = (i + 1) * color_step;
        int color2 = 255 - (i + 1) * color_step;
        // cout << "defectColor:================" << defectColor << endl;

        std::vector<vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierachy;
        cv::resize(maskImg, maskImg, cv::Size(img_width, img_height));
        cv::imwrite(szMaskPath, maskImg);
        findContours(maskImg.clone(), contours,hierachy,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
        // cout << "2:============" << endl;

        cout << "contours.size:============" << contours.size() << endl;

        int max_h = -1;
        int font_face = cv::FONT_HERSHEY_SIMPLEX;
        double font_scale = 0.5;
        int thickness = 1;
        for (int h = 0; h < contours.size(); h++) {
            cv::Rect rect = boundingRect(contours[h]);
            // cout << "rect:============" << rect << endl;

            int tmpArea = rect.width * rect.height;
            int tmpLength = rect.height;
            // cout << "tmpArea:============" << tmpArea << endl;
            if (tmpArea < minArea) {
                continue;
            } else if (tmpLength < minLength) {
                continue;
            } else {
                max_h = h;
            }

            int baseline;
            // 获取文本框的长宽
            cv::Size text_size = cv::getTextSize(txt, font_face, font_scale, thickness, &baseline);
            // 将文本框居中绘制
            cv::Point origin;
            origin.x = rect.x - text_size.width;
            origin.y = rect.y;

            drawContours(frame, contours, max_h, cv::Scalar(0, color1, color2), cv::FILLED);
            
            string content = txt + "-area: " + to_string(tmpArea) + "-length: " + to_string(tmpLength);
            PLOG_DEBUG << "area_length: " << content;

            cv::putText(frame, txt, origin, font_face, font_scale, cv::Scalar(0, color1, color2), thickness, 1, 0);
        }

        //cv::imwrite("final.jpg", frame);
        cv::imwrite(szFinalPath, frame);		
    }

    gettimeofday(&aft, NULL);
    curaft = aft.tv_sec;
    taft = localtime(&curaft);
    int aftend = aft.tv_sec*1000 + aft.tv_usec/1000;
    int afttime = aftend-aftstart;
    cout <<taft->tm_hour <<":"<<taft->tm_min <<":"<<taft->tm_sec<<" reprocessing over,time consumed:" << afttime  << " ms" <<endl;
    PLOG_DEBUG << "reprocessing time: " << afttime;

    int sumtime = pretime + invoketime + afttime;
    cout <<"sum time consumed:" << sumtime  << " ms" <<endl;
    PLOG_DEBUG << "sum time: " << sumtime;
    
    free(m_PositionOutput);
	free(out_data);	
    cout << "检测完成" << endl;
    PLOG_INFO << "检测完成";


// /////////////////////////////////////////////////////////// zip   //////////////////////////////////////////////////
    auto now = std::chrono::system_clock::now();
    std::time_t time_stamp = std::chrono::system_clock::to_time_t(now);
    std::tm time_date = *std::localtime(&time_stamp);

    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();

    // // 将毫秒部分转换为字符串
    std::string milliseconds_str = std::to_string(milliseconds % 1000);

    // 确保结果始终包含 3 位数字
    std::ostringstream milliseconds_stream;
    milliseconds_stream << std::setw(3) << std::setfill('0') << milliseconds_str;
    milliseconds_str = milliseconds_stream.str();

    // 格式化日期时间为字符串，包括毫秒部分
    std::ostringstream time_str_stream;
    time_str_stream << std::put_time(&time_date, "%Y%m%d_%H%M%S") << milliseconds_str ;
    std::string time_str = time_str_stream.str();

    //std::cout << "Formatted Time Stamp: " << time_str << std::endl;

    std::string zip_file_path = release_id + "_" + release_version +  "_" + time_str + ".zip";

    char szCommand[1024];
    //sprintf(szCommand, "cd %s; zip %s%s %s %s %s > /dev/null 2>&1", szDirPath, target_folder_path.c_str(), zip_file_path.c_str(), "origin.jpg", "mask.jpg", "final.jpg");
    // sprintf(szCommand, "cd %s; zip %s%s origin.jpg mask.jpg final.jpg > /dev/null 2>&1; rm -f *", szDirPath, target_folder_path.c_str(), zip_file_path.c_str());
    sprintf(szCommand, "cd %s; zip %s%s origin.jpg mask.jpg final.jpg > /dev/null 2>&1", szDirPath, target_folder_path.c_str(), zip_file_path.c_str());
	cout << szCommand << endl;
    int zipcommandResult = system(szCommand);
    if (zipcommandResult != 0) {
        std::cerr << "The zip command failed to be executed, value:  " << szCommand << "   " << zipcommandResult << std::endl;
        return -1;
    }

    //  usleep(10000);

    return 0;

}

//加入多线程支持 
#define THREAD_COUNT 1

// 线程池中每个线程的参数结构体
typedef struct thread_arg {
    pthread_t thread_id; // 线程标识符
    pthread_mutex_t mutex; // 用于控制对线程状态同步访问的互斥体
    pthread_cond_t cond; // 条件变量，用于等待/通知线程可用状态	
    int is_available; // 是否可用状态，1 为可用，0 为不可用
	DetectModel model; //模型
	cv::Mat frame;     //传递进来的图像数据	
} ThreadArg;

// 线程工作函数
void* thread_func(void* arg) {
    ThreadArg* thread_data = (ThreadArg*)arg;
    
    while(1) {
        pthread_mutex_lock(&thread_data->mutex);
        //while(!thread_data->is_available) {
            // 等待条件变量，即等待任务
            pthread_cond_wait(&thread_data->cond, &thread_data->mutex);
        //}
        thread_data->is_available = 0; // 设置为忙碌
        pthread_mutex_unlock(&thread_data->mutex);
		
        // 执行任务
		cout << "thread " <<thread_data->thread_id << "  start to handle the data " <<endl;
		mainhandle(thread_data->frame, thread_data->model);
        
        // 任务结束，线程重新设为可用状态
        pthread_mutex_lock(&thread_data->mutex);
        thread_data->is_available = 1;
        pthread_mutex_unlock(&thread_data->mutex);
    }

    return NULL;
}
ThreadArg threads[THREAD_COUNT];

void readStaticImg(string img_path)
{
    signal(SIGINT, sigint_handler);
    DIR *dir;
    struct dirent *entry;
    
    while(!stop_sign){
        // data_sign = true;
        // while(data_sign && (!stop_sign)){
        //     usleep(100);
        // }
        if(stop_sign)
        {
            break;
        }
            
         // 打开文件夹
        dir = opendir("imgs");
        if (dir == nullptr) {
            std::cout << "无法打开文件夹" << std::endl;
            break;
        }

        // 遍历文件夹中的所有文件
        while ((entry = readdir(dir)) != nullptr) {
            std::cout << entry->d_name << std::endl;
            // if (data_sign) {
            //     // 从文件夹读图
            //     string imgName = entry->d_name;
            //     string img_path = "imgs/" + imgName;

            //     SDKframe = cv::imread(img_path);
            //     data_sign = false;
            // }
            string imgName = entry->d_name;
            string img_path = "imgs/" + imgName;
            SDKframe = cv::imread(img_path);
            // //////////////////////////////////////////// 线程调用 /////////////////////////////////////

            //如果是thread count ==1， 就不启动多线程模式，还是单线程
            if (THREAD_COUNT == 1)
            {
                cout << "enter simple thread from static img===============" << endl;
                mainhandle(SDKframe, threads[0].model);
            }
            else
            {
                cout << "enter multi thread from static img===============" << endl;
                ThreadArg* thread_data = NULL;		
                while (1){
                    // 查找可用线程
                    for (int i = 0; i < THREAD_COUNT; ++i) {
                        pthread_mutex_lock(&threads[i].mutex);
                        if (threads[i].is_available) {
                            thread_data = &threads[i];					
                            cout << "Found one is_available thread " << i << " thread Id=" << thread_data->thread_id <<endl;					
                            break; // 找到可用线程，跳出循环
                        }
                        pthread_mutex_unlock(&threads[i].mutex);
                    }
                    
                    if (thread_data) {
                        // 生成并设置任务数据
                        //frame
                        SDKframe.copyTo(thread_data->frame);
                        
                        thread_data->is_available = 0;
                        pthread_mutex_unlock(&thread_data->mutex);
                        // 通知工作线程有新任务
                        pthread_cond_signal(&thread_data->cond);
                        break;
                    } else {
                        // 如果当前没有可用线程，主线程等待后继续查找
                        usleep(100000);
                    }			
                }
            }
        }
        // 关闭文件夹
        closedir(dir);    
    }
}

int work_with_internal(string & camera_config_path, string & release_path, string & model_config_path, string & defect_config_path, string & custom_config_path){
    signal(SIGINT, sigint_handler);
    Camera camera;
    int8_t res;

    loadconfigfile(release_path,model_config_path,defect_config_path, custom_config_path);
	
    //////////////////////////////////////////////// 加载模型 ////////////////////////////////////////////////
	
	cout << "Thread Count = " << THREAD_COUNT << endl;

    // if (0 >= THREAD_COUNT)
    // {
    //     THREAD_COUNT = 1;
    // }

    // 初始化线程参数、创建线程
    for (int i = 0; i < THREAD_COUNT; ++i) {
        threads[i].is_available = 1;
		
		cout << i << " model.init start" << endl;
		if (threads[i].model.init(model_path,output_nodes) < 0)
		{
			cout << " model.init failed" << endl;
			return -1;
		}

       //如果是thread count ==1， 就不启动多线程模式，还是单线程，仅仅保存一个变量
       if (THREAD_COUNT > 1)
	   {			
			pthread_mutex_init(&threads[i].mutex, NULL);
			pthread_cond_init(&threads[i].cond, NULL);
			pthread_create(&threads[i].thread_id, NULL, thread_func, &threads[i]);
	   }
    }
	

    cout << " model.init over, begin work" << endl;

    // 1 是使用相机取图，否则为静态读图
    cout << "isCamera:=======" << isCamera << endl;

    if (1 != isCamera)
    {
        ///////////////////////////////////////////////// 静态读图 ////////////////////////////////////
        readStaticImg(imgPath);
        return 0;
    }
    else
    {

        // //////////////////////////////////////////// 相机读图 ////////////////////////////////////
        //////////////////////////////////////////////// open camera ////////////////////////////////////////////////
        res = open_camera_with_internal(camera, camera_config_path);
        if (0 > res){
            cout << "Camera startup failure" << endl;
            return -1;
        }
        camera.start_capture();

        while(!stop_sign){
            data_sign = true;
            while(data_sign && (!stop_sign)){
                usleep(100);
            }
            if(stop_sign)
                break;

            //如果是thread count ==1， 就不启动多线程模式，还是单线程
            if (THREAD_COUNT == 1)
        	{
        		cout << "enter mainhandle 1===============" << endl;
        		mainhandle(SDKframe, threads[0].model);			
        	}
        	else
        	{
        		ThreadArg* thread_data = NULL;		
        		while (1){
        			// 查找可用线程
        			for (int i = 0; i < THREAD_COUNT; ++i) {
        				pthread_mutex_lock(&threads[i].mutex);
        				if (threads[i].is_available) {
        					thread_data = &threads[i];					
        					cout << "Found one is_available thread " << i << " thread Id=" << thread_data->thread_id <<endl;					
        					break; // 找到可用线程，跳出循环
        				}
        				pthread_mutex_unlock(&threads[i].mutex);
        			}
                    
        			if (thread_data) {
        				// 生成并设置任务数据
        				//frame
        				SDKframe.copyTo(thread_data->frame);
                        
        				thread_data->is_available = 0;
        				pthread_mutex_unlock(&thread_data->mutex);
        				// 通知工作线程有新任务
        				pthread_cond_signal(&thread_data->cond);
        				break;
        			} else {
        				// 如果当前没有可用线程，主线程等待后继续查找
        				usleep(100000);
        			}			
        		}
        	}

        }
        return 0;

    }
	
    // 释放内存
    /*int result = model.release();
    if(result != EXIT_SUCCESS){
        printf("sample : interpreter->destory() failed !\n");
        return EXIT_FAILURE;
    }
    // camera.stop_capture();
    cout << "stop work" << endl;
	*/
    // return 0;
}


int main(int argc, char * argv[]){

    string defect_config_path = "config/defect.config";
    string model_config_path = "config/model.config";
    string camera_config_path = "config/camera.config";
    string release_path ="./release.txt";
    string custom_config_path = "config/custom.config";

    bool parsingSuccessful;
    Json::Reader reader;
    Json::Value camera_config;

    int mode;

    string save_path = "aid.log";
    plog::init(plog::debug, save_path.c_str());

    // PLOG_DEBUG << "debug log";     
    // PLOG_INFO << "info log";       
    // PLOG_WARNING << "warning log"; 
    // PLOG_ERROR << "error log";     
    // PLOG_FATAL << "fatal log";

    std::ifstream camera_config_file(camera_config_path);
    parsingSuccessful = reader.parse(camera_config_file, camera_config);
    if (!parsingSuccessful) {
        std::cout << "Failed to parse the camera_config  file!" << std::endl;
    }else {
        mode = camera_config["triggerWay"].asInt();
        std::cout << "triggerWay: " << mode << std::endl;
    }

    current_global_path = "global";
    if (!directoryExists(current_global_path)) {
        if (createDirectory(current_global_path)) {
            std::cout << "Created 'global' folder in current directory. " << current_global_path << std::endl;
        } else {
            std::cerr << "Failed to create the global folder in the current folder. " << current_global_path << std::endl;
        }
    } else {
        std::cout << "The 'global' folder already exists in current directory. " << current_global_path << std::endl;
    }

    target_folder_path = "/var/opt/aidlux/global/";
    if (!directoryExists(target_folder_path)) {
        if (createDirectory(target_folder_path)) {
            std::cout << "Created 'global' folder in current directory. " << target_folder_path << std::endl;
        } else {
            std::cerr << "Failed to create the global folder in the current folder. " << target_folder_path << std::endl;
        }
    } else {
        std::cout << "The 'global' folder already exists in current directory. " << target_folder_path << std::endl;
    }


    //两种模式：1：启动相机一次，然后采图+推理  2，反复 启动相机+采图+推理
    string smode = "1";
    if(argc >= 2)
    {
        smode = argv[1];
    }

    if(smode == "1"){
        int res = work_with_internal(camera_config_path, release_path, model_config_path, defect_config_path, custom_config_path);
    } else if (smode == "2"){
//        int res = work_with_internal2(camera_config_path, release_path, model_config_path, defect_config_path, current_global_path, target_folder_path);
    }

    return 0;

}
