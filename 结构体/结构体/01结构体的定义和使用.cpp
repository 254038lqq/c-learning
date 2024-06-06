#include<iostream>
#include<string>
using namespace std;

//1. 结构体定义
// 创建学生数据类型：学生包括（姓名、年龄、分数）
// 自定义数据类型  一些类型几何组成的一个类型
struct Student {
	//成员列表
	//姓名
	string name;
	//年龄
	int age;
	//分数
	int score;
}s3;

/*
	结构体 创建
	通过结构体创建变量的方式有三种：
		a.struct 结构体名 变量名;
		b.struct 结构体名 变量名 ={ 成员1值，成员2值    ...};
		c.定义结构体时顺便创建结构体变量;
*/

// 通过学生类型创建具体学生
// 结构体创建的
// 2.1 struct Student s1
// 2.2 struct Student s2 = {...}
// 2.3 在定义结构体时顺便创建结构体变量


int main1() {
	//2.1 struct Student s1
	struct Student s1;
	//给 s1 属性赋值 ，通过 . 访问结构体变量中的属性
	s1.name = "张三";
	s1.age = 18;
	s1.score = 98;
	cout << "姓名： " << s1.name << "  年龄： " << s1.age << "  分数： " << s1.score << endl;

	// 2.2 struct Student s2 = {...}
	struct Student s2 = { "李四", 19, 80 };
	cout << "姓名： " << s2.name << "  年龄： " << s2.age << "  分数： " << s2.score << endl;

	// 2.3 在定义结构体时顺便创建结构体变量
	s3.name = "王五";
	s3.age = 16;
	s3.score = 88;
	cout << "姓名： " << s3.name << "  年龄： " << s3.age << "  分数： " << s3.score << endl;

	system("pause");
	return 0;
}