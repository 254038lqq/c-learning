#include<iostream>
#include<string>
#include <map>
using namespace std;


void printMap062(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test06201()
{
	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	//不建议这种方式插入    但是可以用这种方式  利用 key  来访问  value
	cout << m[4] << endl;
	m[10] = 40;
	printMap062(m);
	//删除
	////删除pos迭代器所指的元素，返回下一个元素的迭代器。
	m.erase(m.begin());
	printMap062(m);
	//删除容器中值为key的元素。
	m.erase(3);
	printMap062(m);
	//清空
	//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	m.erase(m.begin(), m.end());
	//清除所有元素
	m.clear();
	printMap062(m);
}
int main062() {
	test06201();
	system("pause");
	return 0;
}