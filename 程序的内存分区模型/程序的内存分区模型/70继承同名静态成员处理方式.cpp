#include<iostream>
#include<string>
using namespace std;
//�̳��е�ͬ����̬��Ա����ʽ

class Base70 {
public: 
    static void func() {
        cout << "Base - static void func()" << endl; 
    } 
    static void func(int a) { 
        cout << "Base - static void func(int a)" << endl; 
    }
      static int m_A;
};
int Base70::m_A = 100;

class Son70 : public Base70 {
public: 
    static void func() { 
    cout << "Son - static void func()" << endl; 
    } 
    static int m_A;
};
int Son70::m_A = 200;
//ͬ����̬��Ա���� 
void test7001() { 
    //ͨ��������� 
    cout << "ͨ��������ʣ� " << endl; 
    Son70 s701; 
    cout << "Son ��m_A = " << s701.m_A << endl; 
    cout << "Base �� mA = " << s701.Base70::m_A << endl;
    //ͨ����������
    cout << "ͨ���������ʣ� " << endl;
    cout << "Son �� m_A = " << Son70::m_A << endl;
    //��һ����������ͨ�������ķ�ʽ����   �ڶ���������������������
    cout << "Base �� m_A = " << Son70::Base70::m_A << endl;
}
//ͬ����̬��Ա���� 
void test7002() { 
    //ͨ��������� 
    cout << "ͨ��������ʣ� " << endl; 
    Son70 s702; 
    s702.func();
    s702.Base70::func();
    cout << "ͨ���������ʣ� " << endl;
    Son70::func();
    Son70::Base70::func();
    //����ͬ������������ص�����������ͬ����Ա��������Ҫ�������������
    Son70::Base70::func(100);
}
int main70() {
    //test7001();

    test7002();

    system("pause");
    return 0;
}