#include<iostream>
#include<string>
using namespace std;
//类模板成员函数类外实现


template<class T1, class T2>
class Person012 {
public:
    //成员函数类内声明
    Person012(T1 name, T2 age);
    void showPerson012();
public:
    T1 m_Name;
    T2 m_Age;
};
//构造函数 类外实现
//  Person012  构造函数的类外实现   Person012::Person012(T1 name, T2 age)  
//  但是编译器不认识 T1，T2   加  template<class T1, class T2>  让编译器知道   T1，T2  的存在
//  如果想告诉他这是一个类模板的成员函数的类外实现  还需要在作用域后面加 <T1, T2> 变成   Person012<T1, T2>::Person012(T1 name, T2 age)
template<class T1, class T2>
Person012<T1, T2>::Person012(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数 类外实现
template<class T1, class T2>
void Person012<T1, T2>::showPerson012() {
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}
void test01201()
{
    Person012<string, int> p("Tom", 20);
    p.showPerson012();
}
int main12() {

    test01201();


    system("pause");
    return 0;
}