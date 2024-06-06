/*
* ===================== 案例1：============================
* ==================== 案例描述 ============================
*     学校正在做毕设项目，每名老师带领5个学生，总共有三个老师，需求如下：
*  设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
*  学生的成员有姓名、考试分数、创建数组存放三名老师，通过函数给每个老师及所带的学生赋值
*  最终打印出老师数据以及老师所带的学生数据
* 
*/

//  报错：引发了异常，读取访问权限冲突
//  原因 写了太多个相同名字的结构体


#include<string>
#include<iostream>
using namespace std;

//时间的头文件
#include<Ctime>


// 定义学生结构体
struct student07 {
	string student_name;
	float student_score;
};
//定义老师结构体
struct teacher07 {
	string teacher_name;
	struct student07 stuarray[5];
};

//给老师和学生赋值的函数
void allocatspace(struct teacher07 tarray[], int len_t ){
	string nameseed = "ABCDE";
	for (int i = 0; i < len_t; i++) {
		tarray[i].teacher_name = "teacher_";
		tarray[i].teacher_name += nameseed[i];

		//通过循环给老师所带的学生赋值
		//float scoreseed[5] = {78, 79, 80, 81, 82};
		for (int j = 0; j < 5; j++) {
			tarray[i].stuarray[j].student_name = "student_";
			//tarray[i].stuarray[j].student_name += nameseed[j];
			tarray[i].stuarray[j].student_name.append(1,nameseed[j]);

			int rondom = rand() % 61 + 40; //40~99
			tarray[i].stuarray[j].student_score = rondom;
		}
	}
};
//打印所有信息
void printinfo(struct teacher07 tarray[], int len_t) {
	for (int i = 0; i < len_t; i++) {
		cout << "老师姓名" << tarray[i].teacher_name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\t学生姓名" << tarray[i].stuarray[j].student_name <<
				",学生分数" << tarray[i].stuarray[j].student_score << endl;

		}
	}
};
int main0701(){

	//随机数种子
	/*
		srand((unsigned int)time(NULL)); 这行代码用于初始化随机数生成器的种子。
		它将当前时间的秒数转换为一个 unsigned int 类型的值，并将其作为 srand() 函数的参数传递，以确保每次程序运行时都会产生不同的随机数序列。
		这样做是因为随机数生成器通常是伪随机的，它们的输出取决于它们的初始状态，称为种子。如果使用相同的种子来初始化随机数生成器，它将产生相同的序列。
		通过将种子设置为不同的值，如当前时间，可以使得每次运行程序时都得到不同的随机数序列。
	*/
	srand((unsigned int)time(NULL));
	//创建三名老师的数组
	struct teacher07 teaarray[3];
	//通过函数给三名老师的信息赋值，并给老师带的学生信息赋值
	//获取老师的长度
	int len_t = sizeof(teaarray) / sizeof(teaarray[0]);
	allocatspace(teaarray, len_t);

	//打印所有老师及所带学生信息
	printinfo(teaarray, len_t);
	system("pause");
	return 0;
}
