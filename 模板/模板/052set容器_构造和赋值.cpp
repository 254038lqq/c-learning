#include <set>
#include<iostream>
#include<string>
using namespace std;
void printSet052(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//����͸�ֵ
void test05201()
{
	set<int> s1;

	//��������ֻ��insert��ʽ
	s1.insert(10);
	s1.insert(50);
	s1.insert(40);
	s1.insert(20);
	s1.insert(20);
	s1.insert(20);

	//��������
	//set�����ص㣬����Ԫ�ز���ʱ���Զ�����
	//set��������������ظ�ֵ   �������� 20 ʱû�б��� ����ӡ���ʱ  ����ֻ��һ��20
	printSet052(s1);   //out��10 20 40 50 

	//��������
	set<int>s2(s1);
	printSet052(s2);
	//��ֵ
	set<int>s3;
	s3 = s2;
	printSet052(s3);
}
int main052() {
	test05201();
	system("pause");
	return 0;
}