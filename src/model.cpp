#include <iostream>
#include <aidlux/aidlite/aidlite.hpp>
#include <unistd.h>
#include <jsoncpp/json/json.h>
#include "example.hpp"

using namespace std;
using namespace Aidlux::Aidlite;

std::vector<std::vector<size_t>> output_tensor_shape_={{1,1001}};

std::vector<std::string> split(const std::string& str)
{
    std::stringstream ss(str);
    std::vector<std::string> elems;
    std::string item;
    while (std::getline(ss, item, ','))
    {
        elems.push_back(item);
    }
    return elems;
}


int DetectModel::init(string detect_model_path, string outNode_names)
{
    // string outNode_names = "Sigmoid_173";
    // string outNode_names = "Conv_198,Conv_217,Conv_236";
    string model_config_path = "config/model.config";
    bool parsingSuccessful;
    Json::Reader reader;
    Json::Value model_config;
    unsigned int OBJ_CLASS_NUM;
    unsigned int input_n;
    unsigned int input_w;
    unsigned int input_h;
    unsigned int input_channel;
    unsigned int output_n;
    unsigned int output_w;
    unsigned int output_h;
    unsigned int output_defect_len;
    std::ifstream model_config_file(model_config_path);
    parsingSuccessful = reader.parse(model_config_file, model_config);
    if (!parsingSuccessful) {
        std::cout << "Failed to parse the model_config file!" << std::endl;
    }else{
        Json::Value& input_shape = model_config[0]["input_shape"];
        input_n =input_shape[0][0].asInt();
        input_h =input_shape[0][1].asInt();
        input_w =input_shape[0][2].asInt();
        input_channel =input_shape[0][3].asInt();

        Json::Value& output_shape = model_config[0]["output_shape"];
        output_n =output_shape[0][0].asInt();
        output_h =output_shape[0][1].asInt();
        output_w =output_shape[0][2].asInt();
        output_defect_len =output_shape[0][3].asInt();

        const Json::Value& class_names_array = model_config[0]["class_names"];
        OBJ_CLASS_NUM = class_names_array.size();
    }


    cout << " detect_model_path:  " << detect_model_path << endl;

    Model* model = Model::create_instance(detect_model_path.c_str());
    if(model == nullptr){
        printf("Create model failed !\n");
        return EXIT_FAILURE;
    }
    // std::vector<std::vector<uint32_t>> input_shapes = {{1,480,480,3}};
    // std::vector<std::vector<uint32_t>> output_shapes = {{1,480,480,1}};

    std::vector<std::vector<uint32_t>> input_shapes = {{input_n, input_w, input_h, input_channel}};
    std::vector<std::vector<uint32_t>> output_shapes = {{output_n, output_w, output_h, output_defect_len}};
    // cout << " input_shapes:  " << input_shapes << " output_shapes: " << output_shapes << endl;

    model->set_model_properties(input_shapes, DataType::TYPE_FLOAT32, output_shapes, DataType::TYPE_FLOAT32);

    Config* config = Config::create_instance();
    if(config == nullptr){
        printf("Create config failed !\n");
        return EXIT_FAILURE;
    }
    config->implement_type = ImplementType::TYPE_FAST;

    //config->framework_type = FrameworkType::TYPE_SNPE;
    //config->accelerate_type = AccelerateType::TYPE_GPU;

    config->framework_type = FrameworkType::TYPE_QNN;
    config->accelerate_type = AccelerateType::TYPE_DSP;

    // std::vector<std::string> output_node_names = split(outNode_names);
    // config->snpe_out_names = output_node_names;
    detect_interpreter = InterpreterBuilder::build_interpretper_from_model_and_config(model, config);
    if(detect_interpreter == nullptr){
        printf("build_interpretper_from_model_and_config failed !\n");
        return EXIT_FAILURE;
    }

    // detect_interpreter->incarnate_logging("./fast_snpe_yolov5_multi_", LogLevel::INFO);

    int result = detect_interpreter->init();
    if(result != EXIT_SUCCESS){
        printf("sample : interpreter->init() failed !\n");
        return EXIT_FAILURE;
    }
    result = detect_interpreter->load_model();
    if(result != EXIT_SUCCESS){
        printf("sample : interpreter->load_model() failed !\n");
        return EXIT_FAILURE;
    }
    printf("detect model load success!\n");
    return 0;

};


int DetectModel::release()
{
    int result = detect_interpreter->destory();
    sleep(1);
    return result;
};


void DetectModel::run(cv::Mat* frame, float *output)
{
    int32_t result = 0;
    // cout << "run ================================start" << std::endl;
    // printf("%f\ncd",frame->at<float>(0));
    // cout << "input_data" << frame->at<float>(0) << std::endl;
    result = detect_interpreter->set_input_tensor(0, frame->data);
    // cout << "run ================================end " << result << std::endl;
    if(result != 0){
        cout << "An error occurred while running: detect_interpreter->set_input_tensor" << std::endl;
    }
    // cout << "run2 ================================ start" << std::endl;

    result = detect_interpreter->invoke();
    if(result != 0){
        cout << "An error occurred while running: detect_interpreter->invoke" << std::endl;
    }
    // cout << "run2 ================================ end" << std::endl;

    float *out_data = nullptr;
    result = detect_interpreter->get_output_tensor(0, (void**)&out_data);
    if (result != 0)
    {
        printf(">> get_output_tensor   error  %d \n", result);
    }

    string model_config_path = "config/model.config";
    bool parsingSuccessful;
    Json::Reader reader;
    Json::Value model_config;
    int output_size;
    int output_width;
    int output_height;

    std::ifstream model_config_file(model_config_path);
    parsingSuccessful = reader.parse(model_config_file, model_config);
    if (!parsingSuccessful) {
        std::cout << "Failed to parse the model_config file!" << std::endl;
    }else{
        output_size = model_config[0]["output_shape"][0][3].asInt();
        output_width = model_config[0]["output_shape"][0][2].asInt();
        output_height = model_config[0]["output_shape"][0][1].asInt();
    }

    // 复制输出到参数中
    // cout << "output: ===================start " << output << " " << out_data << std::endl;
    // cout << "output_size: =================== " << output_size << std::endl;
    // cout << "outputwidth_outputheight: =================== " << output_width << " " << output_height  << std::endl;
    memcpy(output, out_data, sizeof(float)*output_width * output_height*3);
    // cout << "output: ===================end " << output << " " << out_data << std::endl;
    // if(out_data){
    //     for(int i = 0; i < 10; i++) {
    //             cout << std::endl;
    //             std::cout << "out_data====" << (float)out_data[i] << "  ";
    //     }
    //     cout << std::endl;
    // }
};
