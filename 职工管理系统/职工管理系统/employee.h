#pragma once
//��ͨԱ����ͷ�ļ�
#include<iostream>
#include<string>
using namespace std;

#include "worker.h"

class Employee : public Worker {
public:
	//���캯��  ÿ��Ա���ڹ���ʱ��Ӧ�ó�ʼ�������ϵ�����
	Employee(int id, string name,int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};