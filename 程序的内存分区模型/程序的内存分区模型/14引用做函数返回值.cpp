#include<iostream>
#include<string>
using namespace std;
//�����������ķ���ֵ
// 
//1.��Ҫ���ؾֲ�����������
int& test01() {
    int a = 10; //�ֲ����� 
    return a; 
}
//2.�����ĵ��ÿ�����Ϊ��ֵ
int& test02() {
    static int a = 10; //��̬���� �������ȫ������ȫ�����ϵ������ڳ��������ϵͳ�ͷ�
    return a;
}
int main14() {


    ///���ܷ��ؾֲ�����������
    // �ֲ����������ջ����ջ���ɱ������Զ������ͷţ����ܵ�һ��ֵ�ǶԵģ��ڶ��η���ֵ�Ͳ�����
    int& ref1 = test01();
    cout << "ref1 = "<< ref1 <<endl;
    cout << "ref1 = " << ref1 << endl;

    //�����������ֵ����ô���뷵������
    int& ref2 = test02();
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    //��������ķ���ֵ�����ã�����������ÿ�����Ϊ��ֵ
    test02() = 1000;
    cout << "ref2 = " << ref2 << endl;
    cout << "ref2 = " << ref2 << endl;

    system("pause");
    return 0;
}