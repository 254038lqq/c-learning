#include <queue>
#include <string>
#include<iostream>
using namespace std;
class Person044
{
public:
	Person044(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
void test04401() {
	//��������
	queue<Person044> q;
	//׼������
	Person044 p1("��ɮ", 30);
	Person044 p2("�����", 1000);
	Person044 p3("��˽�", 900);
	Person044 p4("ɳɮ", 800); 
	//����������Ԫ�� ��Ӳ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	//���в��ṩ������������֧���������
	while (!q.empty()) {
		cout << "���д�СΪ��" << q.size() << endl;
		//�����ͷԪ��
		cout << "��ͷԪ��-- ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;

		cout << "��βԪ��-- ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;

		cout << endl;
		//������ͷԪ��
		q.pop();
	}
	cout << "���д�СΪ��" << q.size() << endl;
}
int main044() {
	test04401();
	system("pause");
	return 0;
}