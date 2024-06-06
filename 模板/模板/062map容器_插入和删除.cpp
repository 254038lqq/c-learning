#include<iostream>
#include<string>
#include <map>
using namespace std;


void printMap062(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test06201()
{
	//����
	map<int, int> m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair(2, 20));
	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ
	//���������ַ�ʽ����    ���ǿ��������ַ�ʽ  ���� key  ������  value
	cout << m[4] << endl;
	m[10] = 40;
	printMap062(m);
	//ɾ��
	////ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
	m.erase(m.begin());
	printMap062(m);
	//ɾ��������ֵΪkey��Ԫ�ء�
	m.erase(3);
	printMap062(m);
	//���
	//ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
	m.erase(m.begin(), m.end());
	//�������Ԫ��
	m.clear();
	printMap062(m);
}
int main062() {
	test06201();
	system("pause");
	return 0;
}