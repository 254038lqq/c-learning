#include <list>
#include <iostream>
using namespace std;
void printList047(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//大小操作
void test04701()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}
	//重新指定大小
	//resize(num);         //重新指定容器的长度为num，若容器变长，则以默认值 0  填充新位置。
							//如果容器变短，则末尾超出容器长度的元素被删除。
	L1.resize(10);
	printList047(L1);
	L1.resize(2);
	printList047(L1);
	//resize(num, elem);  //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                          //如果容器变短，则末尾超出容器长度的元素被删除。
	L1.resize(5, 100);
	printList047(L1);
}
int main047() {
	test04701();
	system("pause");
	return 0;
}