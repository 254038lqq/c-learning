/*
* ================= �������� ======================
* ���һ��Ӣ�۵Ľṹ�壬������Ա���������䡢�Ա𣻴����ṹ�����飬�����д��5��Ӣ�ۡ�
* ͨ��ð�������㷨���������е�Ӣ�۰��հ���������������������մ�ӡ�����Ľ��
* 5��Ӣ����Ϣ���£�
*	{"����",23,"��"}
*	{"����",22,"��"}
*	{"�ŷ�",20,"��"}
*	{"����",21,"��"}
*	{"����",19,"Ů"}
* 
* 
*	��C++�У����������ݸ�����ʱ��ʵ�����Ǵ�����������׵�ַ����ˣ��ں����ڲ��������Խ�������Ϊһ��ָ�룬ͨ����ָ����Է��������Ԫ�ء�
*/

#include<iostream>
using namespace std;
#include<string>

//1.����Ӣ�۽ṹ��
struct hero {
	string name;
	int age;
	string gender;
};

//ð������
void bubble_sort(struct hero heroarray[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-i-1; j++) {
			if (heroarray[j].age > heroarray[j+1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
};

void bubble_sort2(struct hero* heroarray, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			
			if (heroarray[j].age > heroarray[j + 1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
}
int main0702(){
	//2.����������5��Ӣ��
	struct hero hero_array[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"}
	};
	int len_h = sizeof(hero_array) / sizeof(hero_array[0]);
	//��ӡ����ǰ
	cout << "============== ��ӡ����ǰ���ݣ�==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "������" << hero_array[l].name << "   �Ա�" << hero_array[l].gender << "   ���䣺" << hero_array[l].age << endl;
	};
	//������������򣬰������������������
	//��C++�У����������ݸ�����ʱ��ʵ�����Ǵ�����������׵�ַ��
	bubble_sort(hero_array, len_h);
	//��ӡ����ǰ
	cout << "============== ��ӡ��������ݣ�==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "������" << hero_array[l].name << "   �Ա�" << hero_array[l].gender << "   ���䣺" << hero_array[l].age << endl;
	};
	bubble_sort2(hero_array, len_h);
	//��ӡ����ǰ
	cout << "============== ��ӡ����2�����ݣ�==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "������" << hero_array[l].name << "   �Ա�" << hero_array[l].gender << "   ���䣺" << hero_array[l].age << endl;
	};
	system("pause");
	return 0;

}