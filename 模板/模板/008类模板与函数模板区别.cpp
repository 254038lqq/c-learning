#include<iostream>
#include<string>
using namespace std;

//类模板与函数模板的区别
//类模板
template<class NameType, class AgeType = int>
class Person008
{
public:
    Person008(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }
public:
    NameType m_Name;
    AgeType m_Age;
};
//1、类模板没有自动类型推导的使用方式
void test00801()
{
    // Person p("孙悟空", 1000); // 错误 类模板使用时候，不可以用自动类型推导
    Person008 <string, int>p("孙悟空", 1000); //必须使用显示指定类型的方式，使用类模板
    p.showPerson();
}
//2、类模板在  模板参数列表中  可以有默认参数
void test00802()
{
    Person008 <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数
    p.showPerson();
}

int main008() {
    test00801();
    test00802();



    system("pause");
    return 0;
}