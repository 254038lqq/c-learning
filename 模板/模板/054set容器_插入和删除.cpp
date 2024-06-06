#include <set>
#include<iostream>
#include<string>
using namespace std;

void printSet054(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//�����ɾ��
void test05401()
{
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet054(s1);  //10 20 30 40
	//ɾ��
	//erase(pos); //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	s1.erase(s1.begin()); 
	printSet054(s1); //20 30 40
	//erase(elem); //ɾ��������ֵΪelem��Ԫ�ء�
	s1.erase(30); 
	printSet054(s1); //20 40

	//���
	// erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet054(s1);
}
int main054() {
	test05401();
	system("pause");
	return 0;
}