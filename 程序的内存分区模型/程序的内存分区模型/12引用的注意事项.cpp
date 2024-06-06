#include<iostream>
#include<string>
using namespace std;


int main12() {
    //1.引用必须初始化
    //2.引用在初始化后，不可以改变

    int a = 10;
    //创建引用

    //1.引用必须初始化
    //创建引用
    //int& b;   //错误引用必须初始化
    int& b = a;


    //2.引用在初始化后，不可以改变
    int c = 20;

    b = 20;   //赋值操作，而不是更改引用

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    
    //int& b = c;      //错误，多次初始化
    cout << "b = " << b << endl;


    system("pause");
    return 0;
}