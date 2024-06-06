#include<iostream>
#include<string>
using namespace std;
//函数模板的注意事项
/*
    自动类型推导，必须推导出一致的数据类型T,才可以使用
    模板必须要确定出T的数据类型，才可以使用
*/


//利用模板提供通用的交换函数
template<class T>
void mySwap002(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test00201()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap002(a, b);              // 正确，可以推导出一致的   T 
    //mySwap002(a, c);            // 错误，推导不出一致的     T    类型
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 2、模板必须要确定出  T  的数据类型，才可以使用
template<class T>
void func002()
{
    cout << "func 调用" << endl;
}
void test00202()
{
    //func002(); //错误，模板不能独立使用，必须确定出T的类型
    func002<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}
int main002() {
    test00201();
    test00202();

    system("pause");
    return 0;
}