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
	//默认构造
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList045(L1);
	//构造函数将[beg, end)区间中的元素拷贝给本身
	list<int>L2(L1.begin(), L1.end());
	printList045(L2);
	////拷贝构造函数。
	list<int>L3(L2);
	printList045(L3);
	//构造函数将n个elem拷贝给本身。
	list<int>L4(10, 1000);
	printList045(L4);
}

int main045() {
	test04501();
	system("pause");
	return 0;
}