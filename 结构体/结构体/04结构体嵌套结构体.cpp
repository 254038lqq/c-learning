#include<iostream>
#include<string>
using namespace std;



struct student {
	string namae;
	int age;
	int score;
};
struct teacher {
	int id;
	string namae;
	int age;
	struct student stu;
};

// 结构体嵌套结构体的使用

int main40() {

	//1.创建老师
	struct teacher t;
	t.id = 20231027;
	t.namae = "迷糊老师";
	t.age = 45;
	t.stu.namae = "猪猪侠";
	t.stu.age = 18;
	t.stu.score = 59;


	cout << "老师姓名： " << t.namae << "  老师年龄： " << t.age << "  老师编号： " << t.id << endl;
	cout << "学生姓名： " << t.stu.namae << "  学生年龄： " << t.stu.age << "  学生分数： " << t.stu.score << endl;

	system("pause");
	return 0;
}