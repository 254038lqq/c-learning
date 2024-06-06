#pragma once        //��ֹͷ�ļ��ظ�����
#include<iostream>  //���������������ļ�
using namespace std;  //ʹ�ñ�׼�������ռ�
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

#include<fstream>
#define FILENAME "empFile.txt"
// �������
class WorkerManager {
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//0.�˳�����ϵͳ
	void exitSystem();
	
	// ��¼ְ������
	int m_EmpNum;
	// ְ������ָ��
	Worker** m_EmpArray;

	//1.���ְ��
	void Add_Emp();

	//�����ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpty;
	//ͳ���ļ��е�������
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//2.��ʾְ��
	void Show_Emp();

	//3.ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ��� -1
	int IsExist(int id);

	//4.�޸�ְ��
	void Mod_Emp();
	//5.����ְ��
	void Find_Emp();

	//6.����ְ���������
	void Sort_Emp();

	//7.����ļ�
	void Clean_Emp();
	//��������
	~WorkerManager();

};