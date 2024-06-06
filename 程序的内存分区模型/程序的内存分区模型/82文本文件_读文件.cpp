#include<iostream>
#include<string>.
#include<fstream>
using namespace std;

//文本文件  读文件
// 是以程序为主体的，，写文件是从程序写入文本（从程序输出到文本）  读文件是从文本读入程序（从文本读入到程序）
/*
* 读文件的五个步骤
    1. 包含头文件
        #include <fstream>
    2. 创建流对象
        ifstream ifs;
    3. 打开文件并判断文件是否打开成功
        ifs.open("文件路径",打开方式);
    4. 读数据
        四种方式读取
    5. 关闭文件
        ifs.close();
*/

void test8201() {
    //1.包含头文件  #include <fstream>
    // 
    //2.创建流对象   
    ifstream ifs;

    //3. 打开文件并判断文件是否打开成功   打开方式----读
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    //第一种方式   利用 右移运算符 将 ifs 中的数据 全部写入到  字符数组  buf 中
    //char buf[1024] = { 0 };
    //while (ifs >> buf)
    //{
    // cout << buf << endl;
    //}
    //第二种    利用 getline 将  ifs  中的数据读入到 字符数组 buf 中,sizeof(buf)  ---最多读多少数据
    //char buf[1024] = { 0 };
    //cout << sizeof(buf) << endl;
    //while (ifs.getline(buf,sizeof(buf)))
    //{
    //    cout << buf << endl;
    //}
    //第三种  利用  getline 函数将 ifs 中所有数据读取到 字符串中 string buf 中
    //string buf;
    //while (getline(ifs, buf))
    //{
    // cout << buf << endl;
    //}
    //第四种（不推荐用）  一个一个字符  的将ifs  中的所有数据 全部读到字符型数据 char 中
    // != EOF  如果没有读到文件尾   EOF  end of file  文件尾
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c ;
    }
    //5.关闭文件
    ifs.close();
}
int main82() {


    test8201();

    system("pause");
    return 0;
}