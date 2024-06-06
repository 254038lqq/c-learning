#include <set>
#include<iostream>
#include<string>
using namespace std;


class Person059
{
public:
	Person059(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//仿函数
	//第一个小括号  (）              代表重载的符号
	//第二个小括号 (int v1, int v2)  函数的参数列表
	//在C++中，当自定义一个比较函数对象（如这里的myCompare类）用于关联容器（如std::set）时，该比较函数对象的operator()成员函数需要声明为const。
class comparePerson059
{
public:
	bool operator()(const Person059& p1, const Person059& p2) const
	{
		//按照年龄进行排序 降序
		return p1.m_Age > p2.m_Age;
	}
};
void test05901()
{
	//对于自定义数据类型，set必须指定排序规则才可以插入数据
	set<Person059, comparePerson059> s;
	Person059 p1("刘备", 23);
	Person059 p2("关羽", 27);
	Person059 p3("张飞", 25);
	Person059 p4("赵云", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person059, comparePerson059>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}
int main059() {
	test05901();
	system("pause");
	return 0;
}