#include <set>
#include<iostream>
#include<string>
using namespace std;


class Person059
{
public:
	Person059(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//�º���
	//��һ��С����  (��              �������صķ���
	//�ڶ���С���� (int v1, int v2)  �����Ĳ����б�
	//��C++�У����Զ���һ���ȽϺ��������������myCompare�ࣩ���ڹ�����������std::set��ʱ���ñȽϺ��������operator()��Ա������Ҫ����Ϊconst��
class comparePerson059
{
public:
	bool operator()(const Person059& p1, const Person059& p2) const
	{
		//��������������� ����
		return p1.m_Age > p2.m_Age;
	}
};
void test05901()
{
	//�����Զ����������ͣ�set����ָ���������ſ��Բ�������
	set<Person059, comparePerson059> s;
	Person059 p1("����", 23);
	Person059 p2("����", 27);
	Person059 p3("�ŷ�", 25);
	Person059 p4("����", 21);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	for (set<Person059, comparePerson059>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}
int main059() {
	test05901();
	system("pause");
	return 0;
}