#include <list>
#include<iostream>
using namespace std;

void printList045(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void test04501()
{
	//Ĭ�Ϲ���
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList045(L1);
	//���캯����[beg, end)�����е�Ԫ�ؿ���������
	list<int>L2(L1.begin(), L1.end());
	printList045(L2);
	////�������캯����
	list<int>L3(L2);
	printList045(L3);
	//���캯����n��elem����������
	list<int>L4(10, 1000);
	printList045(L4);
}

int main045() {
	test04501();
	system("pause");
	return 0;
}