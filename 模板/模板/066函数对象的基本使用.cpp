#include<iostream>
#include<string>

using namespace std;

//�������� ���º�����
/*
	����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
	�������󳬳���ͨ�����ĸ����������������Լ���״̬
	�������������Ϊ��������
*/

//дһ���ӷ��ķº���
class MyAdd066 {
public:
	//����С����
	int operator()(int v1, int v2){
		return v1 + v2;
	}
};
//1.����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
void test06601() {
	//ͨ��  �� MyAdd066  ������ һ������   --��������
	MyAdd066 myadd;
	cout << myadd(10, 10) << endl;
}
//2.�������󳬳���ͨ�����ĸ����������������Լ���״̬
class MyPrint066 {
public:
	MyPrint066() {
		this->count = 0;
	}
	void operator()(string test) {
		cout << test << endl;
		this->count++;
	}
	int count;
};

void test06602() {
	MyPrint066 myprint;
	myprint("hellow word!");
	myprint("hellow word!");
	myprint("hellow word!");
	myprint("hellow word!");
	cout << "MyPrint066���õĴ�����" << myprint.count << endl;

}
void doPrint(MyPrint066 & mp,string test) {
	mp(test);
}
void test06603() {
	MyPrint066 myprint03;
	doPrint(myprint03, "hellow C++!");
}
int main066() {
	test06601();
	test06602();

	system("pause");
	return 0;
}