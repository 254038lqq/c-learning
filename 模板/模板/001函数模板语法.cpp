#include<iostream>
#include<string>
using namespace std;


//交换整型函数
void swapInt001(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//交换浮点型函数
void swapDouble001(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}
//1.直接写两个交换函数，但是想要实现其他数据类型的交换需要写很多交换函数
void test00101()
{
    int a = 10;
    int b = 20;
    swapInt001(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble001(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

//2.函数模板
// template<typename T>
    //template-- - 声明创建模板
    //typename -- - 表面其后面的符号是一种数据类型，可以用class代替
    //T-- - 通用的数据类型，名称可以替换，通常为大写字母
template<typename T>
void myswap001(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
//利用模板实现两数交换
void test00102()
{
    int a = 10;
    int b = 20;
    //有两种方式使用函数模板
    //1、自动类型推导
    myswap001(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    //2、显示指定类型
    myswap001<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}
 
int main001() {

    //test00101();
    test00102();

    system("pause");
    return 0;
}