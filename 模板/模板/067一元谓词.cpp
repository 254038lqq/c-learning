#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//һԪν��
class GreaterFive {
public:
	bool operator()(int val) {
		return val > 5;
	}
};

//�º���  ����ֵ������bool�������ͣ���Ϊν��
//һԪν��
void test06701() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}
	//������������û�д���5����
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "δ�ҵ�" << endl;
	}
	else {
		cout << "�ҵ��˴���5����"<<*it << endl;
	}
}
int main() {
	test06701();

	system("pause");
	return 0;
}