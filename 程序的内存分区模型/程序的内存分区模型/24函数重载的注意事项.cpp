#include<iostream>
#include<string>
using namespace std;

/*
�������ص�ע������
    1.������Ϊ��������
    2.����������������Ĭ�ϲ���

*/

// 1.������Ϊ��������

void func241(int& a) {             //int &a =10; ���Ϸ�
    cout << "func241(int& a) �ĵ��ã�" << endl; 
}
void func241(const int &a) {       //const int& =10;
    cout << "func241 (const int &a) �ĵ��ã�" << endl;
}

//2.����������������Ĭ�ϲ���
//������
//
void func242(int a, int b=10) {             
    cout << "func242(int a) �ĵ��ã�" << endl;
}
void func242(int a) {
    cout << "func242(int a) �ĵ��ã�" << endl;
}
int main24() {

    int a = 10;
    func241(a);   //��func241(int& a) �ĵ���

    func241(10);  //�� func241 (const int &a) �ĵ���


    //func242(10);    //�������س��ֶ����ԣ�Ӧ��������


    system("pause");
    return 0;
}