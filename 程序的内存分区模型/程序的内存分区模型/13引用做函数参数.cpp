#include<iostream>
#include<string>
using namespace std;

// ��������
 //1. ֵ���� 
 // ֵ���ݣ��ββ�������ʵ��
//�βθı䣬ʵ�β����
void mySwap01(int a, int b) { 
    int temp = a; 
    a = b; 
    b = temp; 
    cout << "swap01a:" << a << " swap01b:" << b << endl;
}
//2. ��ַ���� 
// //��ַ���ݣ��βλ�����ʵ��
//�βθı䣬ʵ�λ���Ÿı�

void mySwap02(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp; 
    cout << "swap02a:" << *a << " swap02b:" << *b << endl;
}
//3. ���ô��� 
//���ô��ݣ��βλ�����ʵ��
void mySwap03(int& a, int& b) {
    int temp = a;
    a = b; 
    b = temp; 
    cout << "swap03a:" << a << " swap03b:" << b << endl;
}

int main13() {

    int a = 10;
    int b = 20;
    mySwap01(a, b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap02(&a, &b);
    cout << "a:" << a << " b:" << b << endl;
    mySwap03(a, b);
    cout << "a:" << a << " b:" << b << endl;


    system("pause");
    return 0;
}