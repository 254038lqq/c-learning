#pragma once
#include<iostream>
#include<string>
using namespace std;

//ְ��������
class Worker{
public:
	//��Ϊ  ��Ա����
	//��ʾ������Ϣ
	// ����ǰ�����virtual�ؼ��֣�����麯��, ����� = 0 ��ɴ��麯�����д��麯���������������
	virtual void showInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;

	//��Ա����
	//ְ�����
	int m_Id;
	//ְ������
	string m_Name;
	//���ű��
	int m_DeptId;

};
