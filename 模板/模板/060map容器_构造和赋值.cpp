#include<iostream>
#include<string>
#include <map>
using namespace std;

void printMap060(map<string, int>& m)
{
	for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
void test06001()
{
	//�ܽ᣺map������Ԫ�ض��ǳɶԳ��֣���������ʱ��Ҫʹ�ö���
	map<string, int>m; //Ĭ�Ϲ���
	//pair<int, int>(1, 10)  �����������Ķ���
	m.insert(pair<string, int>("A", 10));
	m.insert(pair<string, int>("B", 20));
	m.insert(pair<string, int>("C", 30));
	printMap060(m);
	map<string, int>m2(m); //��������
	printMap060(m2);
	map<string, int>m3;
	m3 = m2; //��ֵ
	printMap060(m3);
}
int main060() {
	test06001();
	system("pause");
	return 0;
}