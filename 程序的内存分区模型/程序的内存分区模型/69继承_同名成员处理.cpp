#include<iostream>
#include<string>
using namespace std;

//�̳���ͬ����Ա����ʽ
    // ��������ͬ����Ա ֱ�ӷ��ʼ���
    // ���ʸ���ͬ����Ա ��Ҫ��������
class Base69 {
public: 
    Base69() { 
        m_A = 100; 
    }
    void func()
    {
        cout << "Base - func()����" << endl;
    }
    void func(int a)
    {
        cout << "Base - func(int a)����" << endl;
    }
public: 
    int m_A;
};
class Son69 : public Base69 {
public: 
    Son69() { 
        m_A = 200; 
    }
      //�������븸��ӵ��ͬ���ĳ�Ա��������������ظ��������а汾��ͬ����Ա����
      
      void func()
      {
          cout << "Son - func()����" << endl;
      }
public: int m_A;
};
//ͬ����Ա���ԵĴ���ʽ
void test6901() {
    Son69 s69;
    cout << "Son�µ�m_A = " << s69.m_A << endl;
    //�������ʸ����б����ص�ͬ����Ա��������Ҫ�Ӹ����������
    cout << "Base�µ�m_A = " << s69.Base69::m_A << endl;

}
//ͬ����Ա�����Ĵ���ʽ
void test6902() {
    Son69 s69;
    //ֱ�ӵ��ã����õ��������е�ͬ����Ա����
    s69.func();
    //�������� ���ɵ��ø����ͬ����Ա����
    s69.Base69::func();
    //��������г��ֺ͸���ͬ���ĳ�Ա������������ͬ����Ա�����ص�����������ͬ����Ա����
    // �������ʵ������б����ص�ͬ����Ա��������Ҫ��������
    //s69.func(100);
    s69.Base69::func(10);
}

int main69() {


    //test6901();
    test6902();

    system("pause");
    return 0;
}