#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

//��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
//Ա����Ϣ�� : ���� ������ɣ����ŷ�Ϊ���߻����������з�
//�����10��Ա�����䲿�ź͹���
//ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
//�ֲ�����ʾԱ����Ϣ
class worker65 {
public:
	string m_name;
	int m_Salary;
};
void createWorker(vector<worker65> &v) {
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		worker65 worker;
		worker.m_name = "Ա��";
		worker.m_name += nameseed[i];

		//int num = rand() % n + a;
		//���е�a����ʼֵ��n - 1 + a����ֵֹ��n�������ķ�Χ��
		worker.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999

		//��Ա�����뵽������
		v.push_back(worker);
	}
}
//Ա�������ʵ��
void setGroup(vector<worker65> &vw,multimap<int,worker65> &mw) {
	for (vector<worker65>::iterator it = vw.begin(); it != vw.end(); it++) {
		//����������ű��
		int depart_id = rand() % 3;   // 0 ,1,2
		//��Ա�����뵽������
		mw.insert(make_pair(depart_id,*it));
	}
}

//
void showWorkerByGroup(multimap<int ,worker65> &mw) {
	cout << "�߻����ţ�" << endl;
	multimap<int,worker65>::iterator pos = mw.find(CEHUA);
	int count = mw.count(CEHUA);
	int index = 0;
	for (; pos != mw.end() &&  index <count ; pos++,index++) {
		cout << "������ " << pos->second.m_name << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "=================================================" << endl;
	cout << "�������ţ�" << endl;
	pos = mw.find(MEISHU);
	count = mw.count(MEISHU);
	index = 0;
	for (; pos != mw.end() && index < count; pos++, index++) {
		cout << "������ " << pos->second.m_name << "���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "=================================================" << endl;
	cout << "�з����ţ�" << endl;
	pos = mw.find(YANFA);
	count = mw.count(YANFA);
	index = 0;
	for (; pos != mw.end() && index < count; pos++, index++) {
		cout << "������ " << pos->second.m_name << "���ʣ�" << pos->second.m_Salary << endl;
	}
}
int main065() {
	srand((unsigned int)time(NULL));
	//1.����Ա��
	vector<worker65> vworker;
	createWorker(vworker);

	////�׶β���
	//for (vector<worker65>::iterator it = vworker.begin(); it != vworker.end(); it++) {
	//	cout << "����: " << it->m_name << "\t����: " << it->m_Salary << endl;

	//}

	//2.Ա������
	multimap<int,worker65> mworker;
	setGroup(vworker,mworker);

	//������ʾԱ��
	showWorkerByGroup(mworker);
	system("pause");
	return 0;
}