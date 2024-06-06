#include<iostream>
#include<string>
using namespace std;

/*
    两种分类方式：
        按参数分为： 有参构造和无参构造
        按类型分为： 普通构造和拷贝构造
    三种调用方式：
        括号法
        显示法
        隐式转换法
*/
//构造函数的分类和调用
//1.分类
//1.按照参数分类  无参构造（默认构造）  有参构造
//2.按类型分为： 普通构造和拷贝构造

class person42 {

public:
    //1.构造函数  进行初始化操作
    //1.1按照参数分类  无参构造（默认构造）  有参构造
    person42() {
        cout << "person42无参构造函数的调用" << endl;
    }
    person42(int a) {
        age = a;
        cout << "person42有参构造函数的调用" << endl;
    }

    //1.2 拷贝构造函数
    //将原先实例化对象的所有属性拷贝到新的对象上面，因为是拷贝，不能修改原先的值，所以加 const 
    person42(const person42 &p) {
        //将传入的对象身上的所有属性，拷贝
        age = p.age;
        cout << "person42拷贝构造函数的调用" << endl;
    }
    //2.析构函数  进行清理操作

    ~person42() {
        cout << "person42析构函数的调用" << endl;
    }
public:
    int age;
};

void test42() {
    person42 p(10);
}
//调用
void test422() {
    //2.1 括号法，常用
    person42 p1;    //默认构造函数调用
    person42 p2(10);  //有参构造函数调用
    person42 p3(p2);  //拷贝构造函数调用
    cout << "p2的年龄为： " << p2.age <<endl;
    cout << "p3的年龄为： " << p3.age << endl;

    //注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    //person42 p2();

    //2.2 显式法
    person42 p4;    //默认构造函数调用
    person42 p5 = person42(10);     //有参构造
    person42 p6 = person42(p5);
    //注意1： person42(10)单独写就是匿名对象 当前行结束之后，系统会立即回收匿名对象，马上析构
    //注意2： 不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    //person42 p6(p4);

    //2.3 隐式转换法
    person42 p7 = 10; // person42 p4 = person42(10);    有参
    person42 p8 = p7; // person42 p5 = person42(p4);    拷贝

}

int main42() {

    //test42();
    test422();

    system("pause");
    return 0;
}