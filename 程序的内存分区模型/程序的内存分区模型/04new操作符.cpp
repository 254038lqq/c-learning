#include<iostream>
#include<string>
using namespace std;

//1. new �Ļ����÷�
int* func4() { 
    //�ڶ���������������
    //���ص��� ���������͵�ָ��
    int* a = new int(10); 
    return a; 
}

void test01() {
    int* p = func4();
    cout << *p << endl;
    cout << *p << endl;
    //�����������ɳ���Ա�����٣�����Ա�����ͷ�
    //����delete�ͷŶ�������
    delete p;
    //�ڴ��Ѿ����ͷţ��ٴη��ʾ��ǷǷ�����
    //cout << *p << endl; //�����ͷŵĿռ䲻�ɷ���

}
//2.�ڶ�������new��������
void test02() {
    //����10���������ݵ����飬�ڶ���
    int* arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        //��10��Ԫ�ظ�ֵ 100~109
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++)
    {
        //��ӡ
        cout << arr[i] << endl;
    }
    //�ͷ����� delete ��� []
    delete[] arr;

}
int main04() {

    ///test01();
    test02();


    system("pause");
    return 0;
}