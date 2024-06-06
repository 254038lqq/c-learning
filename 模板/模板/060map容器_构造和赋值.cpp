#include<iostream>
#include<string>
#include <map>
using namespace std;

void printMap060(map<string, int>& m)
{
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test06001()
{
	//总结：map中所有元素都是成对出现，插入数据时候要使用对组
	map<string, int>m; //默认构造
	//pair<int, int>(1, 10)  创建了匿名的对组
	m.insert(pair<string, int>("A", 10));
	m.insert(pair<string, int>("B", 20));
	m.insert(pair<string, int>("C", 30));
	printMap060(m);
	map<string, int>m2(m); //拷贝构造
	printMap060(m2);
	map<string, int>m3;
	m3 = m2; //赋值
	printMap060(m3);
}
int main060() {
	test06001();
	system("pause");
	return 0;
}