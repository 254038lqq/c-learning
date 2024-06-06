#include<iostream>
#include<string>
using namespace std;

// 交换函数
 //1. 值传递 
 // 值传递，形参不会修饰实参
//形参改变，实参不会变
void mySwap01(int a, int b) { 
    int temp = a; 
    a = b; 
    b = temp; 
    cout << "swap01a:" << a << " swap01b:" << b << endl;
}
//2. 地址传递 
// //地址传递，形参会修饰实参
//形参改变，实参会跟着改变

void mySwap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
    cout << "swap02a:" << *a << " swap02b:" << *b << endl;
}
//3. 引用传递 
//引用传递，形参会修饰实参
void mySwap03(int& a, int& b) {
    int temp = a;
    a = b; 
    b = temp; 
    cout << "swap03a:" << a << " swap03b:" << b << endl;
}

int main13() {

    int a = 10;
    int b = 20;
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;


    system("pause");
    return 0;
}