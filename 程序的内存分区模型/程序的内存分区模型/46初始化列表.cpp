#include<iostream>
#include<string>
using namespace std;

/*
    ���ã� C++�ṩ�˳�ʼ���б��﷨��������ʼ������
    �﷨�����캯��()������1(ֵ1),����2��ֵ2��... {}
*/
class Person46 {
public:
    //1.��ͳ��ʽ��ʼ��
    /*
    Person46(int a, int b, int c) {
        p_a = a;
        p_b = b;
        p_c = c;

    }
    */
    //��ʼ���б��ʼ������
    Person46(int a, int b, int c) :p_a(a), p_b(b), p_c(c) {

    }

    int p_a;
    int p_b;
    int p_c;

};
void test4601() {
    //��ͳ��ʽ��ʼ��
    //Person46 p46(10,20,30);

    Person46 p46(20,30,10);
    cout << " p_a = "<< p46.p_a << endl;
    cout << " p_b = " << p46.p_b << endl;
    cout << " p_c = " << p46.p_c << endl;
}
int main46() {
    test4601();




    system("pause");
    return 0;
}