#pragma once
#pragma once

#include<iostream>
#include<string>
using namespace std;

#include "worker.h"

class Boss : public Worker {
public:
	//���캯��  ÿ��Ա���ڹ���ʱ��Ӧ�ó�ʼ�������ϵ�����
	Boss(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void showInfo();
	//��ȡ��λ����
	virtual string getDeptName();
};