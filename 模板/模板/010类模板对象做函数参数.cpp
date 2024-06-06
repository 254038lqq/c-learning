#include<iostream>
#include<string>
using namespace std;

//类模板对象做函数参数

//类模板
template<class NameType, class AgeType = int>
class Person010
{
public:
    Person010(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson010()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }
public:
    NameType m_Name;
    AgeType m_Age;
};
//1、指定传入的类型
void printPerson0101(Person010<string, int>& p)
{
    p.showPerson010();
}
void test01001()
{
    //类模板对象  p("孙悟空", 100)  做函数参数   传给 printPerson0101 
    Person010 <string, int >p("孙悟空", 100);
    printPerson0101(p);
}
//2、参数模板化
template <class T1, class T2>
void printPerson0102(Person010<T1, T2>& p)
{
    p.showPerson010();
    cout << "T1的类型为： " << typeid(T1).name() << endl;
    cout << "T2的类型为： " << typeid(T2).name() << endl;
}
void test01002()
{
    Person010 <string, int >p("猪八戒", 90);
    printPerson0102(p);
}
//3、整个类模板化
template<class T>
void printPerson0103(T& p)
{
    cout << "T的类型为： " << typeid(T).name() << endl;
    p.showPerson010();
}
void test01003()
{
    Person010 <string, int >p("唐僧", 30);
    printPerson0103(p);
}
int main010() {

    test01001();
    test01002();
    test01003();

    system("pause");
    return 0;
}