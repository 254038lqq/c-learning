#include<iostream>
#include<string>
using namespace std;
//静态成员函数
//i.所有对象共享同一个函数
//ii.静态成员函数只能访问静态成员变量
class person49 {
public:
    //静态成员函数
    static void func49() {
        //静态成员函数可以访问静态成员变量
        p49_A = 10;
        //p49_B = 200;  //静态成员函数  不可以访问  非静态成员函数，，无法区分到底是那个对象的
        cout << "static void func49()调用" << endl;

    }
    //静态成员变量
    //类内声明，类外定义
    static int p49_A;
    //非静态成员变量
    int p49_B;

    //静态成员函数也是有访问权限的
private:
    static void func492() {
        cout << "static void func492()调用" << endl;

    }

};
//类外定义
int person49::p49_A = 100;

void test4901() {
    //静态成员函数的两种访问方式
    //通过对象进行访问
    person49 p49;
    p49.func49();
    //通过类名进行访问
    person49::func49();

    //person49::func492();   //类外访问不到私有静态成员函数
}


int main49() {
    test4901();

    system("pause");
    return 0;
}