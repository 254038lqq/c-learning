#include<iostream>
#include<string>
#include<list>
using namespace std;
class Person051 {
public:
	Person051(string name, int age, int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
public:
	string m_Name; //姓名
	int m_Age; //年龄
	int m_Height; //身高
};
//指定排序规则
bool ComparePerson051(Person051& p1, Person051& p2) {
	//年龄相同时 按 身高降序
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	// 年龄 升序
	{
		return p1.m_Age < p2.m_Age;
	}
}
void test05101() {
	list<Person051> L;
	Person051 p1("刘备", 35, 175);
	Person051 p2("曹操", 45, 180);
	Person051 p3("孙权", 40, 170);
	Person051 p4("赵云", 25, 190);
	Person051 p5("张飞", 35, 160);
	Person051 p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person051>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
	cout << "---------------------------------" << endl;
	L.sort(ComparePerson051); //排序
	for (list<Person051>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
}



int main051() {
	test05101();
	system("pause");
	return 0;
}