#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//二进制文件写文件
class Person83 { 
public: 
    // 使用  类型为 char 的字符串数组  来存储姓名
    char m_Name[64];       
    int m_Age; 
};
//二进制文件 写文件 
void test8301() { 
    //1、包含头文件
    // 
    //2、创建输出流对象
    fstream ofs;

    //3、打开文件
    ofs.open("person.txt", ios::out | ios::binary);

    //创建流对象+打开文件
    //ofstream ofs("person.txt", ios::out | ios::binary);
    

    //4、写文件
    Person83 p = { "李四" , 20 };
    // 直接对 p 取地址  返回的是 一个 *person  类型的数据，将其强转成 (const char*)  sizeof(p) --数据的长度
    ofs.write((const char*)&p, sizeof(p));
    //5、关闭文件
    ofs.close();
}
int main() {

    test8301();

    system("pause");
    return 0;
}