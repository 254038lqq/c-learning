#include<iostream>
#include<string>
using namespace std;

//2.ȫ�ֱ���
int g_a = 10; 
int g_b = 10;

//4.2.1  ȫ�ֳ���---const���ε�ȫ�ֱ���
const int c_g_a = 10; 
const int c_g_b = 10;

int main01() {

    //ȫ����
    // ȫ�ֱ�������̬����������

    //1.����һ����ͨ�ľֲ�����
    int a = 10;
    int b = 10;
    cout << "�ֲ�����a�ĵ�ַ" << (int)&a << endl;
    cout << "�ֲ�����b�ĵ�ַ" << (int)&b << endl;

    cout << "ȫ�ֱ���g_a�ĵ�ַ" << (int)&g_a << endl;
    cout << "ȫ�ֱ���g_b�ĵ�ַ" << (int)&g_b << endl;

    //3.��̬����
    //����ͨ����ǰ��� static  �����ھ�̬����

    static int s_a = 10;
    static int s_b = 10;
    cout << "��̬����s_a��ַΪ�� " << (int)&s_a << endl;
    cout << "��̬����s_b��ַΪ�� " << (int)&s_b << endl;

    //4.����
    //4.1�ַ�������
    cout << "�ַ���������ַΪ�� " << (int)&"hello world" << endl;
    cout << "�ַ���������ַΪ�� " << (int)&"hello world1" << endl;

    //4.2const ���εı���
    //4.2.1 ȫ�ֳ��� -----  const ���ε�ȫ�ֱ�����
    cout << "ȫ�ֳ���c_g_a��ַΪ�� " << (int)&c_g_a << endl;
    cout << "ȫ�ֳ���c_g_b��ַΪ�� " << (int)&c_g_b << endl;

    //4.2 �ֲ�����  ---- const���εľֲ�����
    const int c_l_a = 10;
    const int c_l_b = 10;
    cout << "�ֲ�����c_l_a��ַΪ�� " << (int)&c_l_a << endl;
    cout << "�ֲ�����c_l_b��ַΪ�� " << (int)&c_l_b << endl;

    system("pause");
    return 0;
}