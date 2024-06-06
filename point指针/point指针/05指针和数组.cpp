#include<iostream>
using namespace std;
#include<string>
int main50() {
	//指针和数组
	//利用指针访问数组中的元素
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "数组中第一个元素为：" << arr[0] <<endl;

	int* P = arr;   //数组名就是数组首地址
	cout << "利用指针访问数组中第一个元素为：" << *P << endl;

	for (int i = 0; i < 10; i++) {
		cout << *P << endl;
		P++;
	}

	system("pause");
	return 0;
}