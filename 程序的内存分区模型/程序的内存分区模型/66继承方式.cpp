#include<iostream>
#include<string>
using namespace std;

//�̳з�ʽ


class Base661 { 
public: 
    int m_A;
protected: 
    int m_B; 
private: 
    int m_C; 
};
//�����̳� 
class Son661 :public Base661 { 
public: 
    void func() { 
        m_A = 10;  //�ɷ���publicȨ��              �����еĹ���Ȩ�޳�Ա  ����������Ȼ�ǹ���Ȩ��
        m_B = 10; //�ɷ��� protectedȨ��           �����еı���Ȩ�޳�Ա ����������Ȼ�Ǳ���Ȩ��
        //m_C = 10; //���ɷ���                     �����е�˽��Ȩ�޳�Ա  �����в�����ʲôȨ�޶����ʲ���
    } 
};
void myClass661() {
    Son661 s661; 
    s661.m_A = 100;    //����Ȩ�ޣ����ڿ��Է��ʣ�����Ҳ���Է���
    //s661.m_B = 110;  //���ɷ���  ����Ȩ�ޣ����ڿ��Է��ʣ����ⲻ���Է���
}

//�����̳� 
class Son662:protected Base661{ 
public: 
    void func() {
        m_A = 100; //�ɷ���protectedȨ��     �����еĹ���Ȩ�޳�Ա  �������б�ɱ���Ȩ��
        m_B = 100; //�ɷ���protectedȨ��     �����еı���Ȩ�޳�Ա  ����������Ȼ�Ǳ���Ȩ��
        //m_C; //���ɷ���    �����е�˽��Ȩ�޳�Ա  �����в�����ʲôȨ�޶����ʲ���
    } 
}; 
void myClass662() {
            Son662 s662; //
            //s.m_A; //���ɷ���  �ڱ����̳��У�   �����еĹ���Ȩ�޳�Ա  �������б�ɱ���Ȩ�ޣ����������ʲ���
}
//˽�м̳� 
class Son663:private Base661{ 
public: 
    void func() {
                m_A = 110; //�ɷ���privateȨ��                 �����еĹ���Ȩ�޳�Ա  �������б��˽��Ȩ�޳�Ա
                m_B = 100; //�ɷ���privateȨ��//               �����еı���Ȩ�޳�Ա  �������б��˽��Ȩ�޳�Ա
                //m_C; //���ɷ���         �����е�˽��Ȩ�޳�Ա  �����в�����ʲôȨ�޶����ʲ���
                } 
}; 
void myClass663() {
    Son663 s663;
    // Son3��˽�м̳У����Լ̳�Son3��������GrandSon3�ж��޷����ʵ�
    //s663.m_A = 100;    
    //s661.m_B = 110;  
}

class Grandson3 :public Son663 {
public:
    void func() {    
        // m_A = 100;  
        // m_B = 100;
    }
};
int main66() {




    system("pause");
    return 0;
}