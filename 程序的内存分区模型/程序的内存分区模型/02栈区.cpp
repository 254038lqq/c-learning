#include<iostream>
#include<string>
using namespace std;

//ջ������ע�����-------��Ҫ���ؾֲ������ĵ�ַ
//ջ���������ɱ����������ٺ��ͷ�

int* func() { 

    //�ֲ������������ջ����ջ���������ں���ִ����ɺ��Զ��ͷ�
    int a = 10; 
    //���ؾֲ������ĵ�ַ
    return &a; 
}
int main02() {
    int* p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;    
    cout << *p << endl;
    cout << *p << endl;


    system("pause");
    return 0;
}