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