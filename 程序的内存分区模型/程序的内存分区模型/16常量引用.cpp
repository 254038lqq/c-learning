#include<iostream>
#include<string>
using namespace std;

//��������
//���ã�����������Ҫ���������βΣ���ֹ�����
//�ں����β��б��У����Լ� == const�����β� == ����ֹ�βθı�ʵ��

//��ӡ���ݵĺ���
void showValue(const int& v) {
    //v += 10;     //���󣺱��ʽ�����ǿ��޸ĵ���ֵ
    cout << v << endl; 
 }

int main16() {

    //int& ref = 10; ���ñ�����Ҫһ���Ϸ����ڴ�ռ䣬������д���
    //����const�Ϳ����ˣ��������Ż����룬int temp = 10; const int& ref = temp;
    const int& ref = 10;
    //ref = 100; //����const�󲻿����޸ı���
    cout << ref << endl;
    //���������ó������÷�ֹ������޸�ʵ��
    int a = 10;
    showValue(a);

    cout << a << endl;




    system("pause");
    return 0;
}