#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

void printDeque042(const deque<int>& d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void test042() {
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque042(d);

	sort(d.begin(), d.end());
	printDeque042(d);

	sort(d.begin(), d.end());

}
int main042() {
	test042();
	system("pause");
	return 0;
}