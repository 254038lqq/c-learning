#include<iostream>
#include<string>
using namespace std;

//多继承语法
class Base71 { 
public: 
    Base71() { 
        m_A = 100; 
    } 
public: int m_A; 
};
class Base72 {
public: 
    Base72() {
        m_A = 200; //开始是mB 不会出问题，但是改为mA就会出现不明确
    } 
public:
    int m_A;
};
//语法：class 子类：继承方式 父类1 ，继承方式 父类2 
class Son71 : public Base72, public Base71 { 
public:
    Son71() { 
        m_C = 300;
        m_D = 400;
    } 
public: 
    int m_C; 
    int m_D;
};
//多继承容易产生成员同名的情况 
void test7101() { 
    Son71 s71; 
    cout << "sizeof Son = " << sizeof(s71) << endl; 
    //通过使用类名作用域可以区分调用哪一个基类的成员 
    cout << s71.Base71::m_A << endl; 
    cout << s71.Base72::m_A <<endl; 
}



int main71() {
    test7101();



    system("pause");
    return 0;
}