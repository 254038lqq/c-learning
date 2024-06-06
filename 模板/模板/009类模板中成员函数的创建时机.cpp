#include<iostream>
#include<string>
using namespace std;
/*
    类模板中成员函数和普通类中成员函数创建时机是有区别的：
        普通类中的成员函数一开始就可以创建
        类模板中的成员函数在调用时才创建
*/
class Person0091
{
public:
    void showPerson0091()
    {
        cout << "Person0091 show" << endl;
    }
};
class Person0092
{
public:
    void showPerson0092()
    {
        cout << "Person0092 show" << endl;
    }
};
template<class T>
class MyClass009
{
public:
    //这个成员变量在创建时不能确定它的属性 设置为通用类型
    T obj;
    //类模板中的成员函数，并不是一开始就创建的，而是在模板调用时再生成
    void fun0091() { 
        obj.showPerson0091();
    }
    void fun0092() {
        obj.showPerson0092(); 
    }
};
void test00901()
{
    // 创建的是  Person0091  的实例，但是在写代码时，m.fun0092() 并不提示报错，编译时才会报错，说明函数调用才会去创建成员函数
    MyClass009<Person0091> m;

    m.fun0091();
    // m.fun0092();//编译会出错，说明函数调用才会去创建成员函数
}
int main009() {

    test00901();

    system("pause");
    return 0;
}