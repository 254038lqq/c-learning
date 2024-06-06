#include<iostream>
#include<string>
using namespace std;

//结构体指针
// 
// 
//定义结构体
struct Student {
	//成员列表
	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
};

int main03() {

	//1.创建结构体变量
	//struct Student  s = { {"张三",19,100 } };
	struct Student  s[2] = {{"张三",19,100},{"李四",12,90}, };

	// 通过指针指向结构体变量
	struct Student* p = s;
	//3.通过指针访问结构体变量中的数据
	cout << "姓名： " << p->name << "  年龄： " << p->age << "  分数： " << p->score << endl;

	system("pause");
	return 0;
}