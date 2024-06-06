#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class Person013 {
public:
    //成员函数类内声明
    Person013(T1 name, T2 age);
    void showPerson013();
public:
    T1 m_Name;
    T2 m_Age;
};

// 构造函数 类外实现
template<class T1, class T2>
Person013<T1, T2>::Person013(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数 类外实现
template<class T1, class T2>
void Person013<T1, T2>::showPerson013() {
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}