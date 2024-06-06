#include <opencv2/opencv.hpp>  
#include <opencv2/highgui/highgui.hpp>  
  
int main(int argc, char** argv) {  
    // 读取图像文件  
    cv::Mat img = cv::imread("C:/users/86195/desktop/6.png"); //这里填写你要读取的图像的路径
  
    // 检查图像是否正确读取  
    if (img.empty()) {  
        std::cout << "无法打开或找到图像" << std::endl;  
        return -1;  
    }  
  
    // 创建一个窗口来显示图像  
    cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);  
  
    // 在窗口中显示图像  
    cv::imshow("Display Image", img);  
  
    // 等待键盘输入，然后关闭窗口  
    cv::waitKey(0);  
    return 0;  
}