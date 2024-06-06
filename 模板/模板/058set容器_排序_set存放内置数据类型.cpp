#include <set>
#include<iostream>
#include<string>
using namespace std;

//仿函数 
class MyCompare058
{
public:
	//第一个小括号  (）              代表重载的符号
	//第二个小括号 (int v1, int v2)  函数的参数列表
	//在C++中，当自定义一个比较函数对象（如这里的myCompare类）用于关联容器（如std::set）时，该比较函数对象的operator()成员函数需要声明为const。
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
	//默认从小到大   10 20 30 40 50
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl; 
	//指定排序规则    50 40 30 20 10 
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