#include<iostream>
using namespace std;
#include<string>
int main40() {

	/*
	//1.const����ָ��--------����ָ��
		//ָ���ָ������޸ģ�ָ��ָ���ֵ�������޸�   
	int a = 10;
	int b = 20;
	const int* p = &a;
	p = &b;   //����    ָ���ָ������޸�
	cout << "ָ��pָ���ֵ" << *p << endl;
	//*p = 300;  //����    ָ��ָ���ֵ�����Ը�
	//cout << "ָ��pָ���ֵ" << *p << endl;
	*/

	/*
	//2.const���γ���--------ָ�볣��
		//i.ָ���ָ�򲻿����޸ģ�ָ��ָ���ֵ���Ը�
	int a = 10;
	int b = 20;
	int* const p = &a;
	//p = &b;   //����    ָ���ָ�򲻿����޸�
	//cout << "ָ��pָ���ֵ" << *p << endl;
	*p = 300;  //����    ָ��ָ���ֵ���Ը�
	cout << "ָ��pָ���ֵ" << *p << endl;
	*/

	//3.const������ָ�룬�����γ��� 
		//i.ָ���ָ���ָ��ָ���ֵ���������޸ģ�
	int a = 10;
	int b = 20;
	const int* const p = &a;
	//*p = &b;
	//*p = 30;

	system("pause");
	return 0;
}