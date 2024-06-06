#include<iostream>
#include<string>
using namespace std;
//引用做函数的返回值
// 
//1.不要返回局部变量的引用
int& test01() {
    int a = 10; //局部变量 
    return a; 
}
//2.函数的调用可以作为左值
int& test02() {
    static int a = 10; //静态变量 ，存放在全局区，全局区上的数据在程序结束后系统释放
    return a;
}
int main14() {


    ///不能返回局部变量的引用
    // 局部变量存放在栈区，栈区由编译器自动分配释放，可能第一次值是对的，第二次返回值就不对了
    int& ref1 = test01();
    cout << "ref1 = "<< ref1 <<endl;
    cout << "ref1 = " << ref1 << endl;

    //如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    //如果函数的返回值是引用，这个函数调用可以作为左值
    test02() = 1000;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    system("pause");
    return 0;
}