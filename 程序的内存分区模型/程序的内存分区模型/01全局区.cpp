#include<iostream>
#include<string>
using namespace std;

//2.全局变量
int g_a = 10; 
int g_b = 10;

//4.2.1  全局常量---const修饰的全局变量
const int c_g_a = 10; 
const int c_g_b = 10;

int main01() {

    //全局区
    // 全局变量、静态变量、常量

    //1.创建一个普通的局部变量
    int a = 10;
    int b = 10;
    cout << "局部变量a的地址" << (int)&a << endl;
    cout << "局部变量b的地址" << (int)&b << endl;

    cout << "全局变量g_a的地址" << (int)&g_a << endl;
    cout << "全局变量g_b的地址" << (int)&g_b << endl;

    //3.静态变量
    //在普通变量前面加 static  ，属于静态变量

    static int s_a = 10;
    static int s_b = 10;
    cout << "静态变量s_a地址为： " << (int)&s_a << endl;
    cout << "静态变量s_b地址为： " << (int)&s_b << endl;

    //4.常量
    //4.1字符串常量
    cout << "字符串常量地址为： " << (int)&"hello world" << endl;
    cout << "字符串常量地址为： " << (int)&"hello world1" << endl;

    //4.2const 修饰的变量
    //4.2.1 全局常量 -----  const 修饰的全局变量，
    cout << "全局常量c_g_a地址为： " << (int)&c_g_a << endl;
    cout << "全局常量c_g_b地址为： " << (int)&c_g_b << endl;

    //4.2 局部常量  ---- const修饰的局部变量
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "局部常量c_l_a地址为： " << (int)&c_l_a << endl;
    cout << "局部常量c_l_b地址为： " << (int)&c_l_b << endl;

    system("pause");
    return 0;
}