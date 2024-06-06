#include <set>
#include<iostream>
#include<string>
using namespace std;

void printSet054(set<int>& s)
{
	for (set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
//插入和删除
void test05401()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet054(s1);  //10 20 30 40
	//删除
	//erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
	s1.erase(s1.begin()); 
	printSet054(s1); //20 30 40
	//erase(elem); //删除容器中值为elem的元素。
	s1.erase(30); 
	printSet054(s1); //20 40

	//清空
	// erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
	//s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet054(s1);
}
int main054() {
	test05401();
	system("pause");
	return 0;
}