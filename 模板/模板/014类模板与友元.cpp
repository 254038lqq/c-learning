#include<iostream>
#include<string>
using namespace std;

//2��ȫ�ֺ��������Ԫ ����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ
template<class T1, class T2> 
class Person014;
//��������˺���ģ�壬���Խ�ʵ��д�����棬������Ҫ��ʵ����д�����ǰ���ñ�������ǰ����
//template<class T1, class T2> void printPerson2(Person<T1, T2> & p); 
template<class T1, class T2>
void printPerson0142(Person014<T1, T2>& p)
{
    cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person014
{
    //1��ȫ�ֺ��������Ԫ ����ʵ��
    friend void printPerson(Person014<T1, T2>& p)
    {
        cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
    }
    //ȫ�ֺ��������Ԫ ����ʵ��
    //  ������һ����ͨ�ĺ�������  ��������ĺ���ʵ����һ����ģ��ĺ���ʵ��  ��������  ��Ҫ  ��һ����ģ��Ĳ����б�  
    friend void printPerson0142<>(Person014<T1, T2>& p);
public:
    //���캯��
    Person014(T1 name, T2 age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
private:
    T1 m_Name;
    T2 m_Age;
};

//1��ȫ�ֺ���������ʵ��
void test01401()
{
    Person014 <string, int >p("Tom", 20);
    printPerson(p);
}
//2��ȫ�ֺ���������ʵ��
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