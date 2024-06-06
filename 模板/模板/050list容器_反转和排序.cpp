
#include <list>
#include<iostream>
#include<algorithm>
using namespace std;
void printList050(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
bool myCompare050(int val1, int val2)
{
	return val1 > val2;
}
//反转和排序
void test05001()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList050(L);
	//反转容器的元素
	L.reverse();
	printList050(L);
	//排序
	L.sort(); //默认的排序规则 从小到大
	printList050(L);
	L.sort(greater<int>());
	//list::sort(L.begin(), L.end(),std::greater<int>());
	// L.sort(myCompare050); //指定规则，从大到小

	printList050(L);
}
int main050() {
	test05001();
	system("pause");
	return 0;
}