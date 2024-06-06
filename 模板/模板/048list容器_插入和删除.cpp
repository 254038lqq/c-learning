#include<list>
#include <iostream>
using namespace std;
void printList048(const list<int> &L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++){
		cout << *it << " ";
	}
	cout << endl;

}
void test04801(){
	list<int> L1;

	//push_back(elem);//������β������һ��Ԫ��
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);

	//push_front(elem);//��������ͷ����һ��Ԫ��
	L1.push_front(100);
	L1.push_front(200);
	L1.push_front(300);

	printList048(L1);  // 300 200 100 10 20 30

	//ͷɾ
	L1.pop_front();
	printList048(L1);  //200 100 10 20 30

	//βɾ
	L1.pop_back();
	printList048(L1);  //200 100 10 20 


	//remove(elem);//ɾ��������������elemֵƥ���Ԫ�ء�
	L1.push_back(10000);
	L1.push_back(10000);
	L1.push_back(10000);
	printList048(L1);  //200 100 10 20 10000  10000 10000
	L1.remove(10000);
	printList048(L1); //200 100 10 20

	//����
	list<int>::iterator it = L1.begin();
	L1.insert(++it, 1000);
	printList048(L1);    // 200 1000 100 10 20

	//ɾ��
	it = L1.begin();
	cout << *it << endl;
	//ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
	it = L1.erase(++it);
	cout << *it << endl;
	cout << &(*it) << endl;
	printList048(L1);  //200 100 10 20

	//���
	L1.clear();
	printList048(L1); 


}
int main048(){
	test04801();
	system("pause");
	return 0;
}