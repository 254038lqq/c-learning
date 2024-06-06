#include<iostream>
using namespace std;
int main10() {
	//定义指针
	int a = 10;
	//指针定义的语法： 数据类型 * 指针变量；
	int* P;
	//让指针记录变量a的地址
	P = &a;
	cout << "a的地址" << &a << endl;
	cout << "指针P为" << P << endl;

	//使用指针
	//可以通过解引用的方式来找到指针指向的内存    
	// 指针前加一个 * 代表解引用. eg：*P 可以找到指针指向的内存中的数据

	cout << " *P " << *P << endl;
	// 对内存中的数据进行修改
	*P = 11000;
	cout << " a=  " << a << endl;
	cout << " *P=  " << *P << endl;

	system("pause");
	return 0;




}