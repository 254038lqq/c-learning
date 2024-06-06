#include <list>
#include<iostream>
using namespace std;

//const ���� �޶���ֹ�޸�
void printList046(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//��ֵ�ͽ���
void test04601()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList046(L1);
	//��ֵ

	// 1. =
	list<int>L2;
	L2 = L1;
	printList046(L2);
	//2.��[beg, end)�����е����ݿ�����ֵ������
	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList046(L3);
	//��n��elem������ֵ������
	list<int>L4;
	L4.assign(10, 100);
	printList046(L4);
}
//����
void test04602()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	list<int>L2;
	L2.assign(10, 100);
	cout << "����ǰ�� " << endl;
	printList046(L1);
	printList046(L2);
	cout << endl;
	L1.swap(L2);
	cout << "������ " << endl;
	printList046(L1);
	printList046(L2);
}
int main046() {
	test04601();
	test04602();
	system("pause");
	return 0;
}