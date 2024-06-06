#include<iostream>
#include<string>
using namespace std;

/*
函数重载的注意事项
    1.引用作为重载条件
    2.函数重载碰到函数默认参数

*/

// 1.引用作为重载条件

void func241(int& a) {             //int &a =10; 不合法
    cout << "func241(int& a) 的调用！" << endl; 
}
void func241(const int &a) {       //const int& =10;
    cout << "func241 (const int &a) 的调用！" << endl;
}

//2.函数重载碰到函数默认参数
//二义性
//
void func242(int a, int b=10) {             
    cout << "func242(int a) 的调用！" << endl;
}
void func242(int a) {
    cout << "func242(int a) 的调用！" << endl;
}
int main24() {

    int a = 10;
    func241(a);   //走func241(int& a) 的调用

    func241(10);  //走 func241 (const int &a) 的调用


    //func242(10);    //函数重载出现二义性，应尽量避免


    system("pause");
    return 0;
}