#include<iostream>
#include<string>
using namespace std;

//�ṹ��ָ��
// 
// 
//����ṹ��
struct Student {
	//��Ա�б�
	//����
	string name;
	//����
	int age;
	//����
	int score;
};

int main03() {

	//1.�����ṹ�����
	//struct Student  s = { {"����",19,100 } };
	struct Student  s[2] = {{"����",19,100},{"����",12,90}, };

	// ͨ��ָ��ָ��ṹ�����
	struct Student* p = s;
	//3.ͨ��ָ����ʽṹ������е�����
	cout << "������ " << p->name << "  ���䣺 " << p->age << "  ������ " << p->score << endl;

	system("pause");
	return 0;
}