#include<iostream>
#include<string>
using namespace std;

//纯虚函数和抽象类
class Base77 {
public: 
    //纯虚函数 
    //类中只要有一个纯虚函数就称为抽象类 
    // 抽象类的特点：
        //1. 抽象类无法实例化对象 
        // 2.子类必须重写父类中的纯虚函数，否则也属于抽象类 
    virtual void func77() = 0;
};
class Son77 :public Base77 { 
public: 
    //子类必须重写父类中的纯虚函数，否则无法实例化对象
    virtual void func77() { 
        cout << "func 函数调用" << endl;
    };
};
void test7701() {
    // Base77 b77;       //错误，抽象类无法实例化对象
    // new Base77;      //错误，抽象类无法实例化对象

    // new的是什么对象，他就调用的什么对象的func77函数，
    //多态的目的就是让我们的函数接口更通用化，通过一个父类指针，由于指向的对象不同，可以调用不同的函数
    Base77* base = NULL; 
    base = new Son77;
    base->func77(); 
    delete base;   //记得销毁 
}
int main77() {

    test7701();


    system("pause");
    return 0;
}