#include<iostream>
#include<string>
using namespace std;

//template<class T1, class T2>
//class Person013 {
//public:
//    //成员函数类内声明
//    Person013(T1 name, T2 age);
//    void showPerson013();
//public:
//    T1 m_Name;
//    T2 m_Age;
//};

//构造函数 类外实现
//template<class T1, class T2>
//Person013<T1, T2>::Person013(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
////成员函数 类外实现
//template<class T1, class T2>
//void Person013<T1, T2>::showPerson013() {
//    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
//}

//1.直接包含源文件
//#include"013person03.cpp"
//2.将.h 和 .cpp中的内容写到一起  并更改后缀名为.hpp，hpp是约定的名称，并不是强制
#include"013person013.hpp"
void test01301()
{
    Person013<string, int> p("Tom", 20);
    p.showPerson013();
}
int main013() {

    test01301();


    system("pause");
    return 0;
}