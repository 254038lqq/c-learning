#include <set>
#include<iostream>
#include<string>
using namespace std;
void printSet052(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//构造和赋值
void test05201()
{
	set<int> s1;

	//插入数据只有insert方式
	s1.insert(10);
	s1.insert(50);
	s1.insert(40);
	s1.insert(20);
	s1.insert(20);
	s1.insert(20);

	//遍历容器
	//set容器特点，所有元素插入时候自动排序
	//set容器不允许插入重复值   插入三个 20 时没有报错 但打印输出时  里面只有一个20
	printSet052(s1);   //out：10 20 40 50 

	//拷贝构造
	set<int>s2(s1);
	printSet052(s2);
	//赋值
	set<int>s3;
	s3 = s2;
	printSet052(s3);
}
int main052() {
	test05201();
	system("pause");
	return 0;
}