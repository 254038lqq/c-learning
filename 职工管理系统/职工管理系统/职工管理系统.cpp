#include<iostream>
#include<string>

#include "workerManager.h"
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<tuple>

using namespace std;


int main() {

	//���Դ���
	//Worker* worker= NULL;
	//worker = new Employee(1, "����", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "����", 3);
	//worker->showInfo();
	//delete worker;

	// ctrl + K ,ctrl + c ����ע��
	// ctrl +k,ctrl + u 
	//����һ��������Ķ���
	WorkerManager wm;
	int choise = 0;
	while (true) {
		wm.Show_Menu();
		cout << "����������ѡ�� " << endl;
		cin >> choise;   // �����û���ѡ��
		switch (choise)
		{
		case 0:   //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:   //���ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			wm.Show_Emp();
			break;
		case 3:  //ɾ��ְ��
		//{
		//	//����
		//	int ret = wm.IsExist(1);
		//	if (ret != -1) {
		//		cout << "ְ������" << endl;
		//	}
		//	else {
		//		cout << "ְ��������" << endl;
		//	}

		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4:   //�޸�ְ��
		{
			wm.Mod_Emp();
			break; 
		}
		case 5:   //����ְ��
			wm.Find_Emp();
			break;
		case 6:  //����ְ��
			wm.Sort_Emp();
			break;
		case 7:  //����ĵ�
			wm.Clean_Emp();
			break;
		default:
			system("cls");  //����
			break;
		}

	}


	system("pause");  //�밲���������
	return 0;
}