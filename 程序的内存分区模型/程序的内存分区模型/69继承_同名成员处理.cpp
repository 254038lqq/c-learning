#include<iostream>
#include<string>
using namespace std;

//继承中同名成员处理方式
    // 访问子类同名成员 直接访问即可
    // 访问父类同名成员 需要加作用域
class Base69 {
public: 
    Base69() { 
        m_A = 100; 
    }
    void func()
    {
        cout << "Base - func()调用" << endl;
    }
    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }
public: 
    int m_A;
};
class Son69 : public Base69 {
public: 
    Son69() { 
        m_A = 200; 
    }
      //当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
      
      void func()
      {
          cout << "Son - func()调用" << endl;
      }
public: int m_A;
};
//同名成员属性的处理方式
void test6901() {
    Son69 s69;
    cout << "Son下的m_A = " << s69.m_A << endl;
    //如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    cout << "Base下的m_A = " << s69.Base69::m_A << endl;

}
//同名成员函数的处理方式
void test6902() {
    Son69 s69;
    //直接调用，调用的是子类中的同名成员函数
    s69.func();
    //加作用域 即可调用父类的同名成员函数
    s69.Base69::func();
    //如果子类中出现和父类同名的成员函数，子类会的同名成员会隐藏掉父类中所有同名成员函数
    // 如果想访问到父类中被隐藏的同名成员函数，需要加作用域
    //s69.func(100);
    s69.Base69::func(10);
}

int main69() {


    //test6901();
    test6902();

    system("pause");
    return 0;
}