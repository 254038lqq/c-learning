#include"boss.h"

//����������  Employee::

// ���캯����ʵ��
Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;

}
//��ʾ������Ϣ 
void Boss::showInfo() {
	cout << "ְ����ţ�" << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\t��λ: " << this->getDeptName()
		<< "\t��λְ�� ����˾���е�����" << endl;

}
//��ȡ��λ����
string Boss::getDeptName() {
	return string("�ܲ�");
}