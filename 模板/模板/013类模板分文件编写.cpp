#include<iostream>
#include<string>
using namespace std;

//template<class T1, class T2>
//class Person013 {
//public:
//    //��Ա������������
//    Person013(T1 name, T2 age);
//    void showPerson013();
//public:
//    T1 m_Name;
//    T2 m_Age;
//};

//���캯�� ����ʵ��
//template<class T1, class T2>
//Person013<T1, T2>::Person013(T1 name, T2 age) {
//    this->m_Name = name;
//    this->m_Age = age;
//}
////��Ա���� ����ʵ��
//template<class T1, class T2>
//void Person013<T1, T2>::showPerson013() {
//    cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
//}

//1.ֱ�Ӱ���Դ�ļ�
//#include"013person03.cpp"
//2.��.h �� .cpp�е�����д��һ��  �����ĺ�׺��Ϊ.hpp��hpp��Լ�������ƣ�������ǿ��
#include"013person013.hpp"
void test01301()
{
    Person013<string, int> p("Tom", 20);
    p.showPerson013();
}
int main013() {

    test01301();


    system("pause");
    return 0;
}