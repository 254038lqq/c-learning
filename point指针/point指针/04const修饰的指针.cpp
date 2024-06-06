#include<iostream>
using namespace std;
#include<string>
int main40() {

	/*
	//1.const修饰指针--------常量指针
		//指针的指向可以修改，指针指向的值不可以修改   
	int a = 10;
	int b = 20;
	const int* p = &a;
	p = &b;   //可以    指针的指向可以修改
	cout << "指针p指向的值" << *p << endl;
	//*p = 300;  //错误    指针指向的值不可以改
	//cout << "指针p指向的值" << *p << endl;
	*/

	/*
	//2.const修饰常量--------指针常量
		//i.指针的指向不可以修改，指针指向的值可以改
	int a = 10;
	int b = 20;
	int* const p = &a;
	//p = &b;   //错误    指针的指向不可以修改
	//cout << "指针p指向的值" << *p << endl;
	*p = 300;  //错误    指针指向的值可以改
	cout << "指针p指向的值" << *p << endl;
	*/

	//3.const即修饰指针，又修饰常量 
		//i.指针的指向和指针指向的值都不可以修改，
	int a = 10;
	int b = 20;
	const int* const p = &a;
	//*p = &b;
	//*p = 30;

	system("pause");
	return 0;
}