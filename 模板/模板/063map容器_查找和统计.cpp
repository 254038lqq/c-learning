#include<iostream>
#include<string>
#include <map>
using namespace std;


//���Һ�ͳ��
void test06301()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	//����
	////����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "�ҵ���Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
	//ͳ��
	////ͳ��key��Ԫ�ظ���
	int num = m.count(3);
	cout << "num = " << num << endl;
}
int main063() {
	test06301();
	system("pause");
	return 0;
}