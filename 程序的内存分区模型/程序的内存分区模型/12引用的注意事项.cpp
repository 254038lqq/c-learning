#include<iostream>
#include<string>
using namespace std;


int main12() {
    //1.���ñ����ʼ��
    //2.�����ڳ�ʼ���󣬲����Ըı�

    int a = 10;
    //��������

    //1.���ñ����ʼ��
    //��������
    //int& b;   //�������ñ����ʼ��
    int& b = a;


    //2.�����ڳ�ʼ���󣬲����Ըı�
    int c = 20;

    b = 20;   //��ֵ�����������Ǹ�������

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    
    //int& b = c;      //���󣬶�γ�ʼ��
    cout << "b = " << b << endl;


    system("pause");
    return 0;
}