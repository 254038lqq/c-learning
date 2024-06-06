#include<iostream>
#include<string>
using namespace std;

//const的使用场景

//定义学生结构体
struct student {
	string name;
	int age;
	int score;
};

// 打印学生信息的函数
// 值传递 void printstudent(struct student s)
// 将函数中的形参改为指针，可以减少内存空间的占用，而且不会复制新的副本出来
// 但是会存在一个隐患，如果在函数中修改某些属性的值，会修改实参的值
//加入const之后，一旦有修改的操作就会报错，可以防止误造作
void printstudent(const struct student * s) {
	//s->score = 90;  //操作失败，因为加入了const修饰
	cout << "子函数1学生姓名： " << s->name << "  学生年龄： " << s->age << "  学生分数： " << s->score << endl;

}

int main60() {

	//1.创建学生
	struct student s2 = { "李四", 19, 80 };
	cout << "姓名： " << s2.name << "  年龄： " << s2.age << "  分数： " << s2.score << endl;

	printstudent(&s2);
	cout << "0 % 1 = " << 0 % 1 << endl;

	system("pause");
	return 0;
}