#include<iostream>
using namespace std;
#include<string>
int main20() {
	// ָ����ռ���ڴ�ռ�
	int a = 10;
	//ָ�붨����﷨�� �������� * ָ�������
	int* P = &a;

	cout << "sizeof (int *) = " << sizeof(P) << endl;

	string string123 = "hellow word!";
	string* q = &string123;
	cout << "sizeof (char *) = " << sizeof(q) << endl;


	system("pause");
	return 0;




}