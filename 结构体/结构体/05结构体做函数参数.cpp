#include<iostream>
#include<string>
using namespace std;

//�ṹ������������

//����ѧ���ṹ��
struct student {
	string namae;
	int age;
	int score;
};

// ��ӡѧ����Ϣ�ĺ���
// 1.ֵ����
void printstudent1(struct student s) {
	s.score = 80;
	cout << "�Ӻ���1ѧ�������� " << s.namae << "  ѧ�����䣺 " << s.age << "  ѧ�������� " << s.score << endl;

}
// 2.��ַ����
void printstudent2(struct student* p) {    //��ָ��ȥ���ܵ�ַ
	p->score = 90;
	cout << "�Ӻ���2ѧ�������� " << p->namae << "  ѧ�����䣺 " << p->age << "  ѧ�������� " << p->score << endl;

}
// �ṹ������������
//��ѧ�����뵽һ�������У���ӡѧ�����ϵ�������Ϣ
int main50() {

	//1.����ѧ��
	struct student s;
	s.namae = "������";
	s.age = 18;
	s.score = 59;
	printstudent1(s);
	printstudent2(&s);
	cout << "main����ѧ�������� " << s.namae << "  ѧ�����䣺 " << s.age << "  ѧ�������� " << s.score << endl;

	system("pause");
	return 0;
}