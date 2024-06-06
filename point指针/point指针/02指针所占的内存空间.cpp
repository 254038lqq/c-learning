#include<iostream>
using namespace std;
#include<string>
int main20() {
	// 指针所占的内存空间
	int a = 10;
	//指针定义的语法： 数据类型 * 指针变量；
	int* P = &a;

	cout << "sizeof (int *) = " << sizeof(P) << endl;

	string string123 = "hellow word!";
	string* q = &string123;
	cout << "sizeof (char *) = " << sizeof(q) << endl;


	system("pause");
	return 0;




}