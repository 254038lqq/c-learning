#include<iostream>
#include<string>
using namespace std;
//��ģ���Ա��������ʵ��


template<class T1, class T2>
class Person012 {
public:
    //��Ա������������
    Person012(T1 name, T2 age);
    void showPerson012();
public:
    T1 m_Name;
    T2 m_Age;
};
//���캯�� ����ʵ��
//  Person012  ���캯��������ʵ��   Person012::Person012(T1 name, T2 age)  
//  ���Ǳ���������ʶ T1��T2   ��  template<class T1, class T2>  �ñ�����֪��   T1��T2  �Ĵ���
//  ��������������һ����ģ��ĳ�Ա����������ʵ��  ����Ҫ������������ <T1, T2> ���   Person012<T1, T2>::Person012(T1 name, T2 age)
template<class T1, class T2>
Person012<T1, T2>::Person012(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//��Ա���� ����ʵ��
template<class T1, class T2>
void Person012<T1, T2>::showPerson012() {
    cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
}
void test01201()
{
    Person012<string, int> p("Tom", 20);
    p.showPerson012();
}
int main12() {

    test01201();


    system("pause");
    return 0;
}