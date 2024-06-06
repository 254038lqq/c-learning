#include<iostream>
#include<string>
using namespace std;

//成员变量 和 函数 是分开存储的
class person5001 {

};
void test5001() {
    person5001 person50;
    //空对象占用内存空间为：1
    //c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置
    //每个空对象也应该有一个独一无二的内存地址
    cout << "size of p = " << sizeof(person50) << endl;
}
class person5002 {
    int person5002_a;    // 非静态成员变量                             属于类的对象上的数据
    static int person5002_b;    // 静态成员变量  类内声明  类外初始化   不属于类的对象上
    int func5002(){}    // 非静态成员函数                               不属于类的对象上
    static int func5003() {}    // 静态成员函数                               不属于类的对象上
};
int person5002_b = 20;
void test5002() {
    person5002 person5002;
    cout << "size of p = " << sizeof(person5002) << endl;
}
int main50() {

    //test5001();
    test5002();


    system("pause");
    return 0;
}