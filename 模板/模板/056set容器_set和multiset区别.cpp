#include <set>
#include<iostream>
#include<string>

using namespace std;

//set��multiset����
void test05601()
{
	set<int> s;
	//- set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
	//pair  ����  ��һ��Ϊ���صĵ�����  �ڶ���ֵΪ һ�� bool ֵ ��ʾ�Ƿ����ɹ�
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second) {
		cout << "��һ�β���ɹ�!" << endl;
	}
	else {
		cout << "��һ�β���ʧ��!" << endl;
	}
	ret = s.insert(10);
	if (ret.second) {
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else {
		cout << "�ڶ��β���ʧ��!" << endl;
	}

	//multiset
	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
int main056() {
	test05601();
	system("pause");
	return 0;
}