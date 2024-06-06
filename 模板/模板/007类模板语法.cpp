#include<iostream>
#include<string>
using namespace std;

//类模板
template<class NameType, class AgeType>
class Person007
{
public:
    Person007(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson007()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }
public:
    NameType m_Name;
    AgeType m_Age;
};
void test00701()
{
    // 指定NameType 为string类型，AgeType 为 int类型
    Person007<string, int>P1("孙悟空", 999);
    P1.showPerson007();
}

int main007() {

    test00701();


    system("pause");
    return 0;
}