#include<iostream>
#include<string>
using namespace std;
//静态成员变量
class person48 {
public:
    //i.所有对象共享同一份数据
    //ii.在编译阶段分配内存
    //iii.类内声明，类外初始化
    static int p_A;

//静态成员变量也是有访问权限的
private:
    static int p_B;
};

//类外初始化
//int p_A =100；这样写是一个全局变量，要加上  person48::   表示为  person48  作用域下的 一个静态成员
int person48::p_A = 100;
int person48::p_B = 200;
void test4801() {
    person48 p48;
    cout << p48.p_A << endl;

    person48 p482;
    //将静态成员变量修改为200

    p48.p_A = 200;
    //这个时候 静态成员变量的值被修改了
    cout << p48.p_A << endl;
}
//静态成员变量不属于某个对象，因为所有的对象都共享同一份数据
//因此静态成员变量有两种访问方式
//1.通过对象进行访问.
//2.通过类名进行访问
void test4802() {
    //1.通过对象进行访问
    person48 p48;
    cout << p48.p_A << endl;
    //2.通过类名进行访问
    cout << person48::p_A << endl;

    //3.静态成员变量也是有访问权限的
    //cout << person48::p_B << endl;   //私有权限，不可访问
}

int main48() {
    //test4801();
    test4802();
    system("pause");
    return 0;
}