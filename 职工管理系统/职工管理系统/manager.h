#pragma once
//��ͨԱ����ͷ�ļ�
#include<iostream>
#include<string>
using namespace std;

#include "worker.h"

class Manager : public Worker {
public:
	//���캯��  ÿ��Ա���ڹ���ʱ��Ӧ�ó�ʼ�������ϵ�����
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};