#include<iostream>
#include<string>
using namespace std;

//const��ʹ�ó���

//����ѧ���ṹ��
struct student {
	string name;
	int age;
	int score;
};

// ��ӡѧ����Ϣ�ĺ���
// ֵ���� void printstudent(struct student s)
// �������е��βθ�Ϊָ�룬���Լ����ڴ�ռ��ռ�ã����Ҳ��Ḵ���µĸ�������
// ���ǻ����һ������������ں������޸�ĳЩ���Ե�ֵ�����޸�ʵ�ε�ֵ
//����const֮��һ�����޸ĵĲ����ͻᱨ�����Է�ֹ������
void printstudent(const struct student * s) {
	//s->score = 90;  //����ʧ�ܣ���Ϊ������const����
	cout << "�Ӻ���1ѧ�������� " << s->name << "  ѧ�����䣺 " << s->age << "  ѧ�������� " << s->score << endl;

}

int main60() {

	//1.����ѧ��
	struct student s2 = { "����", 19, 80 };
	cout << "������ " << s2.name << "  ���䣺 " << s2.age << "  ������ " << s2.score << endl;

	printstudent(&s2);
	cout << "0 % 1 = " << 0 % 1 << endl;

	system("pause");
	return 0;
}