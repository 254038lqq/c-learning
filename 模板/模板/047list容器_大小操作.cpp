#include <list>
#include <iostream>
using namespace std;
void printList047(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//��С����
void test04701()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ�� " << L1.size() << endl;
	}
	//����ָ����С
	//resize(num);         //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ 0  �����λ�á�
							//���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	L1.resize(10);
	printList047(L1);
	L1.resize(2);
	printList047(L1);
	//resize(num, elem);  //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
                          //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
	L1.resize(5, 100);
	printList047(L1);
}
int main047() {
	test04701();
	system("pause");
	return 0;
}