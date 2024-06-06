#include <deque>
#include<iostream>
using namespace std;
void printDeque040(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//���˲���
void test04001()
{
	deque<int> d;
	//β��
	d.push_back(10);
	d.push_back(20);
	//ͷ��
	d.push_front(100);
	d.push_front(200);
	printDeque040(d);
	//βɾ
	d.pop_back();
	//ͷɾ
	d.pop_front();
	printDeque040(d);
}
//����
void test04002()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque040(d);
	d.insert(d.begin(), 1000);

	d.insert(d.begin()+2, 1000);
	printDeque040(d);
	d.insert(d.begin(), 2, 10000);
	printDeque040(d);
	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);
	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque040(d);
}
//ɾ��
void test04003() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque040(d);
	d.erase(d.begin());
	printDeque040(d);
	d.erase(d.begin(), d.end());
	d.clear();
	printDeque040(d);
}
int main040() {
	//test04001();
	//test04002();
	test04003();

	system("pause");
	return 0;
}