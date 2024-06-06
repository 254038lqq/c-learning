#include<iostream>
using namespace std;
//1.值传递
void swap01(int a, int b) {
	int temp = a;
	a = b;
	b = temp;
	cout << "swap01a:  " << a << endl;
	cout << "swap01b:  " << b << endl;
}
//2.地址传递
void swap02(int* p1, int* p2) {
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
	cout << "01a:  " << *p1 << endl;
	cout << "01b:  " << *p2 << endl;

}
int main60() {

	//指针和函数
	// 
	//1.值传递   ------------- 不会改变实参
	int a = 10;
	int b = 20;
	//swap01(a, b);

	//2.地址传递  -------------  地址传递会改变实参
	swap02(&a, &b);


	cout << "a:  " << a << endl;
	cout << "b:  " << b << endl;
	system("pause");
	return 0;
}