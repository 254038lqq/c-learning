#include<iostream>
#include<string>
using namespace std;


int* func2() { 
    //���� new �ؼ���  ���Խ����ݿ��ٵ�����
    //���ص����¿��ٿռ�ĵ�ַ���
    //��ָ����ܷ��صĵ�ַ
    //ָ�뱾����Ҳ�Ǿֲ�����������ջ�ϣ�ָ�뱣������ݷ��ڶ���
    int* a = new int(10); 
    return a; 
}
int main03() {

    //�ڶ�����������
    //��ָ����ܵ�ַ�ķ���ֵ
    int* p = func2();

    cout << *p << endl;



    system("pause");
    return 0;
}