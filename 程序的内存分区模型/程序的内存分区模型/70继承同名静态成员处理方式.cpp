#include<iostream>
#include<string>
using namespace std;
//继承中的同名静态成员处理方式

class Base70 {
public: 
    static void func() {
        cout << "Base - static void func()" << endl; 
    } 
    static void func(int a) { 
        cout << "Base - static void func(int a)" << endl; 
    }
      static int m_A;
};
int Base70::m_A = 100;

class Son70 : public Base70 {
public: 
    static void func() { 
    cout << "Son - static void func()" << endl; 
    } 
    static int m_A;
};
int Son70::m_A = 200;
//同名静态成员属性 
void test7001() { 
    //通过对象访问 
    cout << "通过对象访问： " << endl; 
    Son70 s701; 
    cout << "Son 下m_A = " << s701.m_A << endl; 
    cout << "Base 下 mA = " << s701.Base70::m_A << endl;
    //通过类名访问
    cout << "通过类名访问： " << endl;
    cout << "Son 下 m_A = " << Son70::m_A << endl;
    //第一个：：代表通过类名的方式访问   第二个：：代表父类作用域下
    cout << "Base 下 m_A = " << Son70::Base70::m_A << endl;
}
//同名静态成员函数 
void test7002() { 
    //通过对象访问 
    cout << "通过对象访问： " << endl; 
    Son70 s702; 
    s702.func();
    s702.Base70::func();
    cout << "通过类名访问： " << endl;
    Son70::func();
    Son70::Base70::func();
    //出现同名，子类会隐藏掉父类中所有同名成员函数，需要加作作用域访问
    Son70::Base70::func(100);
}
int main70() {
    //test7001();

    test7002();

    system("pause");
    return 0;
}