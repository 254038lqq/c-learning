#include <stack>
#include<iostream>
using namespace std;
//ջ�������ýӿ�
void test04301() {
	//����ջ���� ջ������������Ƚ����
	stack<int> s;
	//��ջ�����Ԫ�أ����� ѹջ ��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	//ֻҪջ��Ϊ�գ��Ͳ鿴ջ�� ������ִ�г�ջ����
	while (!s.empty()) {
		cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
		//���ջ��Ԫ��
		cout << "ջ��Ԫ��Ϊ�� " << s.top() << endl;
		//����ջ��Ԫ��
		s.pop();
	}
	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}
int main043() {
	test04301();
	system("pause");
	return 0;
}