#include<iostream>
#include<string>
using namespace std;

//2、全局函数配合友元 类外实现 - 先做函数模板声明，下方在做函数模板定义，在做友元
template<class T1, class T2> 
class Person014;
//如果声明了函数模板，可以将实现写到后面，否则需要将实现体写到类的前面让编译器提前看到
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 
template<class T1, class T2>
void printPerson0142(Person014<T1, T2>& p)
{
    cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person014
{
    //1、全局函数配合友元 类内实现
    friend void printPerson(Person014<T1, T2>& p)
    {
        cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
    }
    //全局函数配合友元 类外实现
    //  这里是一个普通的函数声明  但是类外的函数实现是一个类模板的函数实现  所以这里  需要  加一个空模板的参数列表  
    friend void printPerson0142<>(Person014<T1, T2>& p);
public:
    //构造函数
    Person014(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

//1、全局函数在类内实现
void test01401()
{
    Person014 <string, int >p("Tom", 20);
    printPerson(p);
}
//2、全局函数在类外实现
void test01402()
{
    Person014 <string, int >p("Jerry", 30);
    printPerson0142(p);
}
int main014() {
    test01401();
    test01402();


    system("pause");
    return 0;
}