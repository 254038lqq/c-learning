#include<iostream>
#include<string>
using namespace std;
//����ģ���ע������
/*
    �Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
    ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
*/


//����ģ���ṩͨ�õĽ�������
template<class T>
void mySwap002(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// 1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test00201()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap002(a, b);              // ��ȷ�������Ƶ���һ�µ�   T 
    //mySwap002(a, c);            // �����Ƶ�����һ�µ�     T    ����
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
}

// 2��ģ�����Ҫȷ����  T  ���������ͣ��ſ���ʹ��
template<class T>
void func002()
{
    cout << "func ����" << endl;
}
void test00202()
{
    //func002(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
    func002<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}
int main002() {
    test00201();
    test00202();

    system("pause");
    return 0;
}