#include<iostream>
#include<string>
using namespace std;

//1. �ṹ�嶨��
// ����ѧ���������ͣ�ѧ�����������������䡢������
// �Զ�����������  һЩ���ͼ�����ɵ�һ������
struct Student {
	//��Ա�б�
	//����
	string name;
	//����
	int age;
	//����
	int score;
}s3;

/*
	�ṹ�� ����
	ͨ���ṹ�崴�������ķ�ʽ�����֣�
		a.struct �ṹ���� ������;
		b.struct �ṹ���� ������ ={ ��Ա1ֵ����Ա2ֵ    ...};
		c.����ṹ��ʱ˳�㴴���ṹ�����;
*/

// ͨ��ѧ�����ʹ�������ѧ��
// �ṹ�崴����
// 2.1 struct Student s1
// 2.2 struct Student s2 = {...}
// 2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����


int main1() {
	//2.1 struct Student s1
	struct Student s1;
	//�� s1 ���Ը�ֵ ��ͨ�� . ���ʽṹ������е�����
	s1.name = "����";
	s1.age = 18;
	s1.score = 98;
	cout << "������ " << s1.name << "  ���䣺 " << s1.age << "  ������ " << s1.score << endl;

	// 2.2 struct Student s2 = {...}
	struct Student s2 = { "����", 19, 80 };
	cout << "������ " << s2.name << "  ���䣺 " << s2.age << "  ������ " << s2.score << endl;

	// 2.3 �ڶ���ṹ��ʱ˳�㴴���ṹ�����
	s3.name = "����";
	s3.age = 16;
	s3.score = 88;
	cout << "������ " << s3.name << "  ���䣺 " << s3.age << "  ������ " << s3.score << endl;

	system("pause");
	return 0;
}