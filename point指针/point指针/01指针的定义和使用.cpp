#include<iostream>
using namespace std;
int main10() {
	//����ָ��
	int a = 10;
	//ָ�붨����﷨�� �������� * ָ�������
	int* P;
	//��ָ���¼����a�ĵ�ַ
	P = &a;
	cout << "a�ĵ�ַ" << &a << endl;
	cout << "ָ��PΪ" << P << endl;

	//ʹ��ָ��
	//����ͨ�������õķ�ʽ���ҵ�ָ��ָ����ڴ�    
	// ָ��ǰ��һ�� * ���������. eg��*P �����ҵ�ָ��ָ����ڴ��е�����

	cout << " *P " << *P << endl;
	// ���ڴ��е����ݽ����޸�
	*P = 11000;
	cout << " a=  " << a << endl;
	cout << " *P=  " << *P << endl;

	system("pause");
	return 0;




}