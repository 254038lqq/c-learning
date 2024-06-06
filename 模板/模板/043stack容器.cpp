#include <stack>
#include<iostream>
using namespace std;
//栈容器常用接口
void test04301() {
	//创建栈容器 栈容器必须符合先进后出
	stack<int> s;
	//向栈中添加元素，叫做 压栈 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	//只要栈不为空，就查看栈顶 ，并且执行出栈操作
	while (!s.empty()) {
		cout << "栈的大小为：" << s.size() << endl;
		//输出栈顶元素
		cout << "栈顶元素为： " << s.top() << endl;
		//弹出栈顶元素
		s.pop();
	}
	cout << "栈的大小为：" << s.size() << endl;
}
int main043() {
	test04301();
	system("pause");
	return 0;
}