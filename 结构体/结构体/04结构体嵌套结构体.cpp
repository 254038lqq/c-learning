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

// �ṹ��Ƕ�׽ṹ���ʹ��

int main40() {

	//1.������ʦ
	struct teacher t;
	t.id = 20231027;
	t.namae = "�Ժ���ʦ";
	t.age = 45;
	t.stu.namae = "������";
	t.stu.age = 18;
	t.stu.score = 59;


	cout << "��ʦ������ " << t.namae << "  ��ʦ���䣺 " << t.age << "  ��ʦ��ţ� " << t.id << endl;
	cout << "ѧ�������� " << t.stu.namae << "  ѧ�����䣺 " << t.stu.age << "  ѧ�������� " << t.stu.score << endl;

	system("pause");
	return 0;
}