#include<iostream>
#include<string>
using namespace std;

/*
��ͨ�����뺯��ģ������
    ��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
    ����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
    ���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
*/
//��ͨ����
int myAdd00401(int a, int b)
{
    return a + b;
}
//����ģ��
template<class T>
T myAdd00402(T a, T b)
{
    return a + b;
}
//ʹ�ú���ģ��ʱ��������Զ������Ƶ������ᷢ���Զ�����ת��,����ʽ����ת��
void test00401()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    char d = 'd';

    cout << myAdd00401(a, c) << endl; //��ȷ����char���͵�'c'��ʽת��Ϊint���� 'c' ��Ӧ ASCII��99
     //myAdd02(a, c); // ��������ģ����ã�ʹ���Զ������Ƶ�ʱ�����ᷢ����ʽ����ת��
     //myAdd00402<char>(a, c); //��ȷ���������ʾָ�����ͣ����Է�����ʽ����ת��
     cout << myAdd00402<int>(a, c) << endl;
}
int main004() {

    test00401();


    system("pause");
    return 0;
}