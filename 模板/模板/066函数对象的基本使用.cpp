#include<iostream>
#include<string>

using namespace std;

//函数对象 （仿函数）
/*
	函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
	函数对象超出普通函数的概念，函数对象可以有自己的状态
	函数对象可以作为参数传递
*/

//写一个加法的仿函数
class MyAdd066 {
public:
	//重载小括号
	int operator()(int v1, int v2){
		return v1 + v2;
	}
};
//1.函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
void test06601() {
	//通过  类 MyAdd066  来创建 一个对象   --函数对象
	MyAdd066 myadd;
	cout << myadd(10, 10) << endl;
}
//2.函数对象超出普通函数的概念，函数对象可以有自己的状态
class MyPrint066 {
public:
	MyPrint066() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	int count;
};

void test06602() {
	MyPrint066 myprint;
	myprint("hellow word!");
	myprint("hellow word!");
	myprint("hellow word!");
	myprint("hellow word!");
	cout << "MyPrint066调用的次数：" << myprint.count << endl;

}
void doPrint(MyPrint066 & mp,string test) {
	mp(test);
}
void test06603() {
	MyPrint066 myprint03;
	doPrint(myprint03, "hellow C++!");
}
int main066() {
	test06601();
	test06602();

	system("pause");
	return 0;
}