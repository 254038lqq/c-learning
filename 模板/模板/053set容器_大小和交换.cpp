#include <set>
#include<iostream>
#include<string>
using namespace std;
void printSet053(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//��С
void test05301()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ�� " << s1.size() << endl;
	}
}
//����
void test05302()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "����ǰ" << endl;
	printSet053(s1);
	printSet053(s2);
	cout << endl;
	cout << "������" << endl;
	s1.swap(s2);
	printSet053(s1);
	printSet053(s2);
}
int main053() {
	test05301();
	test05302();
	system("pause");
	return 0;
}