#include<iostream>
#include<string>
using namespace std;
/*
    默认情况下，c++编译器至少给一个类添加3个函数
        - 1. 默认构造函数(无参，函数体为空)
        - 2. 默认析构函数(无参，函数体为空)
        - 3. 默认拷贝构造函数，对属性进行值拷贝
    构造函数调用规则如下：
        a.如果用户定义有参构造函数，c++不在提供默认无参构造，但是会提供默认拷贝构造
        b.如果用户定义拷贝构造函数，c++不会再提供其他构造函数
*/

class Person44 {
public: 
    //无参（默认）构造函数 
    Person44() {
        cout << "Person44无参构造函数!" << endl; 
    } 
    //有参构造函数
    Person44(int a) { 
        age = a; cout << "Person44有参构造函数!" << endl; 
    } 
    //拷贝构造函数 
    Person44(const Person44 &p) {
        age = p.age; 
        cout << "Person44拷贝构造函数!" << endl; 
    } 
    //析构函数 
    ~Person44() { 
        cout << "Person44析构函数!" << endl; 
    }
public: 
    int age;
};
void test4401() {
    Person44 p1(18); //如果不写拷贝构造，编译器会自动添加拷贝构造，并且做浅拷贝操作
    Person44 p2(p1);
}
void test4402() { 
    //如果用户提供有参构造，编译器不会提供默认构造，会提供拷贝构造 Person p1; 
    //此时如果用户自己没有提供默认构造，会出错 
    Person44 p3(10); 
    //用户提供的有参 
    Person44 p4(p3);
    //此时如果用户没有 提供拷贝构造，编译器会提供
    // 
    //如果用户提供拷贝构造，编译器不会提供其他构造函数
    Person44 p5; //此时如果用户自己没有提供默认构造，会出错
    Person44 p6(10); //此时如果用户自己没有提供有参，会出错
    Person44 p7(p6); //用户自己提供拷贝构造
}
int main44() {
    test4402();



    system("pause");
    return 0;
}