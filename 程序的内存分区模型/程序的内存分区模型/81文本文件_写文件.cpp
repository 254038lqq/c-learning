#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//文本文件  写文件
// 是以程序为主体的，，写文件是从程序写入文本（从程序输出到文本）  读文件是从文本读入程序（从文本读入到程序）
/*
* 写文件的五个步骤：
    1. 包含头文件
        #include <fstream>
    2. 创建流对象
        ofstream ofs;
    3.. 打开文件
        ofs.open("文件路径",打开方式);
    4. 写数据
        ofs << "写入的数据";
    5. 关闭文件
        ofs.close();
*/
void test8101() {
    //1. 包含头文件   #include <fstream>
 
    //2.创建流对象
    //写文件----创建流对象的流向是从本程序指向要写的文件--所以是 output file stream
    ofstream write_file;

    //3.打开文件   打开方式----写
    write_file.open("test.txt", ios::out);

    //4.写数据
    write_file << "姓名：李四" << endl;
    write_file << "年龄：40" << endl;
    write_file << "性别：女" << endl;

    //关闭文件
    write_file.close();


}

int main81() {


    test8101();

    system("pause");
    return 0;
}