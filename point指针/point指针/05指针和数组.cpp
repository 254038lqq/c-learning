#include<iostream>
using namespace std;
#include<string>
int main50() {
	//ָ�������
	//����ָ����������е�Ԫ��
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "�����е�һ��Ԫ��Ϊ��" << arr[0] <<endl;

	int* P = arr;   //���������������׵�ַ
	cout << "����ָ����������е�һ��Ԫ��Ϊ��" << *P << endl;

	for (int i = 0; i < 10; i++) {
		cout << *P << endl;
		P++;
	}

	system("pause");
	return 0;
}