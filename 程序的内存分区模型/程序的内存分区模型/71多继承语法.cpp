#include<iostream>
#include<string>
using namespace std;

//��̳��﷨
class Base71 { 
public: 
    Base71() { 
        m_A = 100; 
    } 
public: int m_A; 
};
class Base72 {
public: 
    Base72() {
        m_A = 200; //��ʼ��mB ��������⣬���Ǹ�ΪmA�ͻ���ֲ���ȷ
    } 
public:
    int m_A;
};
//�﷨��class ���ࣺ�̳з�ʽ ����1 ���̳з�ʽ ����2 
class Son71 : public Base72, public Base71 { 
public:
    Son71() { 
        m_C = 300;
        m_D = 400;
    } 
public: 
    int m_C; 
    int m_D;
};
//��̳����ײ�����Աͬ������� 
void test7101() { 
    Son71 s71; 
    cout << "sizeof Son = " << sizeof(s71) << endl; 
    //ͨ��ʹ������������������ֵ�����һ������ĳ�Ա 
    cout << s71.Base71::m_A << endl; 
    cout << s71.Base72::m_A <<endl; 
}



int main71() {
    test7101();



    system("pause");
    return 0;
}