#include<iostream>
#include<string>
#include<list>
using namespace std;
class Person051 {
public:
	Person051(string name, int age, int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
public:
	string m_Name; //����
	int m_Age; //����
	int m_Height; //���
};
//ָ���������
bool ComparePerson051(Person051& p1, Person051& p2) {
	//������ͬʱ �� ��߽���
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;
	}
	else
	// ���� ����
	{
		return p1.m_Age < p2.m_Age;
	}
}
void test05101() {
	list<Person051> L;
	Person051 p1("����", 35, 175);
	Person051 p2("�ܲ�", 45, 180);
	Person051 p3("��Ȩ", 40, 170);
	Person051 p4("����", 25, 190);
	Person051 p5("�ŷ�", 35, 160);
	Person051 p6("����", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);
	for (list<Person051>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}
	cout << "---------------------------------" << endl;
	L.sort(ComparePerson051); //����
	for (list<Person051>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}
}



int main051() {
	test05101();
	system("pause");
	return 0;
}