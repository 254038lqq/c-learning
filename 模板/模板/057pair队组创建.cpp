#include <set>
#include<iostream>
#include<string>
using namespace std;

//对组创建
void test05701()
{
	//第一种  默认构造
	//<string, int>  指定对组的两个数据类型
	// (string("Tom"), 20)  赋值  
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " << p.first << " 年龄： " << p.second << endl;
	//第二种
	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}
int main057() {
	test05701();
	system("pause");
	return 0;
}