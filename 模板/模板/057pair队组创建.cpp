#include <set>
#include<iostream>
#include<string>
using namespace std;

//���鴴��
void test05701()
{
	//��һ��  Ĭ�Ϲ���
	//<string, int>  ָ�������������������
	// (string("Tom"), 20)  ��ֵ  
	pair<string, int> p(string("Tom"), 20);
	cout << "������ " << p.first << " ���䣺 " << p.second << endl;
	//�ڶ���
	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}
int main057() {
	test05701();
	system("pause");
	return 0;
}