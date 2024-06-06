#include<iostream>
#include<string>
#include <map>
using namespace std;


//查找和统计
void test06301()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	//查找
	////查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	//统计
	////统计key的元素个数
	int num = m.count(3);
	cout << "num = " << num << endl;
}
int main063() {
	test06301();
	system("pause");
	return 0;
}