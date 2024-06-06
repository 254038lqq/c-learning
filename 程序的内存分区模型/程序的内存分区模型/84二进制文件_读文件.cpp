#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//二进制文件   读文件

class Person84 { 
public: 
    char m_Name[64]; 
    int m_Age; 
};
void test8401() {
    //1.包含头文件
    //2.创建流对象
    // ifstream ifs；
    //3.打开文件  判断文件是否成功打开
    //ifs.open("person.txt", ios::in | ios::binary); 
    fstream ifs("person.txt", ios::in | ios::binary); 
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }
    //4.读数据
    Person84 p;
    ifs.read((char*)&p, sizeof(p));
    cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;

    //5.关闭文件
}
int main84() {
    test8401();
    system("pause");
    return 0;
}