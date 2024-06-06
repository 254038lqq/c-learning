#include <set>
#include<iostream>
#include<string>
using namespace std;

//�º��� 
class MyCompare058
{
public:
	//��һ��С����  (��              �������صķ���
	//�ڶ���С���� (int v1, int v2)  �����Ĳ����б�
	//��C++�У����Զ���һ���ȽϺ��������������myCompare�ࣩ���ڹ�����������std::set��ʱ���ñȽϺ��������operator()��Ա������Ҫ����Ϊconst��
	bool operator()(int v1, int v2) const {
		return v1 > v2;
	}
};
void test05801()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	//Ĭ�ϴ�С����   10 20 30 40 50
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl; 
	//ָ���������    50 40 30 20 10 
	set<int, MyCompare058> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);
	for (set<int, MyCompare058>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main058() {
	test05801();
	system("pause");
	return 0;
}