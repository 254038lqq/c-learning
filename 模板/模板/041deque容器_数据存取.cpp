#include<deque>
#include<iostream>
using namespace std;

void printdeque041(deque<int>& d) {
	for (deque<int>::iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << "  ";
	}
	cout << endl;
	
}
void test04101() {
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_back(30);
	d1.push_front(1);
	d1.push_front(2);
	d1.push_front(3);

	printdeque041(d1);

	// ����  [] ��ʽ���� �����е�Ԫ��
	for (int i = 0; i < d1.size(); i++) {
		cout << d1[i] << "  ";
	}
	cout << endl;

	// ���ó�Ա���� at ����
	for (int i = 0; i < d1.size(); i++) {
		cout << d1.at(i) << "  ";
	}
	cout << endl;

	cout << "d1�ĵ�һ��Ԫ��Ϊ��" << d1.front() << endl;
	cout << "d1�����һ��Ԫ��Ϊ��" << d1.back() << endl;
}
int main041() {
	test04101();
	system("pause");
	return 0;
}