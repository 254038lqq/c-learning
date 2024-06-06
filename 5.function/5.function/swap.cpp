//双引号表示是自定义的头文件
#include"swap.h"

//函数的定义
void swap(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << " a= " << a << endl;
	cout << " b= " << b << endl;

}
