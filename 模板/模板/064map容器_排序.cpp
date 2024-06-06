#include<iostream>
#include<string>
#include <map>
using namespace std;

class MyCompare064 {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;
	}
};
void test06401()
{
	//默认从小到大排序
	// 所有元素都会根据元素的键值自动排序
	//利用仿函数实现从大到小排序
	map<int, int, MyCompare064> m;
	m.insert(make_pair(1, 30));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 10));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for (map<int, int, MyCompare064>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}
int main064() {
	test06401();
	system("pause");
	return 0;
}