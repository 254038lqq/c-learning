#include<iostream>
#include<string>
using namespace std;

//�̳��еĶ���ģ��
class Base67 {
public: 
    int m_A; 
protected: 
    int m_B; 
private: 
    int m_C; //˽�г�Աֻ�Ǳ������ˣ����ǻ��ǻ�̳���ȥ
};
//�����̳� 
class Son67 :public Base67 { 
public: 
    int m_D; 
};
void test6701() { 
    //���������еķǾ�̬��Ա���Զ��ᱻ����̳���ȥ
    //�����е�˽�г�Ա���� �Ǳ��������������ˣ�����Ƿ��ʲ���������ȷʵ���̳���ȥ��
    cout << "sizeof Son = " << sizeof(Son67) << endl; 
}
//
//cl /d1 reportSingleClassLayout�鿴������ �����ļ���
int main67() {


    test6701();

    system("pause");
    return 0;
}