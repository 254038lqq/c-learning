#include<iostream>
#include<string>
using namespace std;

//对象的初始化和清理
//1.构造函数  进行初始化操作
//2.析构函数  进行清理操作
class person41 {

public: 
    //1.构造函数  进行初始化操作
    /* 
        1.1 构造函数，没有返回值也不写void
        1.2 函数名称与类名相同
        1.3 构造函数可以有参数，因此可以发生重载
        1.4 程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
    */
    person41() {
        cout << "person41构造函数的调用" << endl;
    }

    //2.析构函数  进行清理操作
    /*
        2.1 析构函数，没有返回值也不写void
        2.2 函数名称与类名相同,在名称前加上符号 ~
        2.3 析构函数不可以有参数，因此不可以发生重载
        2.4 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
    */
    ~person41() {
        cout << "person41析构函数的调用" << endl;
    }
};
//- 构造函数和析构函数都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构函数
void test41() {
    //创建一个对象
    person41 p41;    //在栈上的数据，test41执行完毕后，释放这个对象
}

int main41() {

    test41();

    system("pause");
    return 0;
}