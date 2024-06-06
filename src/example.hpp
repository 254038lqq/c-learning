#ifndef __SMARTVISION_EXAMPLE__
#define __SMARTVISION_EXAMPLE__

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <aidlux/aidlite/aidlite.hpp>

class DetectModel
{
private:
    std::unique_ptr<Aidlux::Aidlite::Interpreter> detect_interpreter;
public:
    int init(std::string detect_model_path,std::string outNode_names);
    int release();
    // void run(cv::Mat* frame, uint8_t** output0);
    // void run(cv::Mat* frame, float* output0, float* output1, float* output2);
    void run(cv::Mat* frame, float *output0);
};

// class DefectLog
// {
//     public:
//         typedef enum ENUM_LOG_TYPE
//         {
//             LOG_NONE,                //不开启日志
//             LOG_ERROR,                //错误日志
//             LOG_RTM,                    //运行日志
//             LOG_DEBUG             //调试日志
//         }LOG_TYPE;

//         #define LOG_FILE_PATH        250
//         #define MAX_LOG_ROW_SIZE    500                //一行日志的大小
//         #define MAX_LOG_FILE_SIZE (10*1024*1024)    //日志文件大小


//     //初始化日志
//     void InitLog();
//     //设置日志参数
//     void SetLogParam(int nLogLevel=LOG_RTM, int nLogFileSize = MAX_LOG_FILE_SIZE);
//     //写日志函数
//     void LOG(LOG_TYPE t, char* format, ...);
// };

#endif
