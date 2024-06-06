#include<iostream>
#include<string>
using namespace std;

//结构体做函数参数

//定义学生结构体
struct student {
	string namae;
	int age;
	int score;
};

// 打印学生信息的函数
// 1.值传递
void printstudent1(struct student s) {
	s.score = 80;
	cout << "子函数1学生姓名： " << s.namae << "  学生年龄： " << s.age << "  学生分数： " << s.score << endl;

}
// 2.地址传递
void printstudent2(struct student* p) {    //用指针去接受地址
	p->score = 90;
	cout << "子函数2学生姓名： " << p->namae << "  学生年龄： " << p->age << "  学生分数： " << p->score << endl;

}
// 结构体做函数参数
//将学生传入到一个参数中，打印学生身上的所有信息
int main50() {

	//1.创建学生
	struct student s;
	s.namae = "猪猪侠";
	s.age = 18;
	s.score = 59;
	printstudent1(s);
	printstudent2(&s);
	cout << "main函数学生姓名： " << s.namae << "  学生年龄： " << s.age << "  学生分数： " << s.score << endl;

	system("pause");
	return 0;
}