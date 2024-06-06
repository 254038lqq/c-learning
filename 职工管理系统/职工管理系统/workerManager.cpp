#include "workerManager.h"

//���캯���Ŀ�ʵ��
WorkerManager::WorkerManager(){
	//��ʼ������
	//�����������ʼ��
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;        //��ʼ������Ϊ0
		this->m_EmpArray = NULL;   //��ʼ������ָ��Ϊ��
		this->m_FileIsEmpty = true;  //��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	//2.�ļ����ڵ�����λ��
	//	���ļ�ʱ���ļ�״̬��ʶ�ǳ�ʼ��״̬��eof()�����Ǹ����ļ�״̬��ʶ���жϵ�ǰ�Ƿ����ļ�β���������ж��ļ��Ƿ�Ϊ�ա�
	// ����ȡ�ļ�����ʱ�������ļ�βʱ��ϵͳ������ļ�״̬��ʶΪ�ļ�β������EOF��־��
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//�ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;        //��ʼ������Ϊ0
		this->m_EmpArray = NULL;   //��ʼ������ָ��Ϊ��
		this->m_FileIsEmpty = true;  //��ʼ���ļ�Ϊ��
		ifs.close();
		return;
	}
	//���ļ����ڣ����Ҳ�Ϊ��ʱ
	int num = this->get_EmpNum();
	//cout << "ְ������Ϊ�� " << num << endl;;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ��е����� �浽������
	this->init_Emp();

	//���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "Ա����ţ� " << this->m_EmpArray[i]->m_Id << "  Ա��������" << this->m_EmpArray[i]->m_Name
	//		<< "  Ա�����ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

//��ʼ��Ա��
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�  ���ļ�
	int id;
	string name;
	int did;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		Worker* worker = NULL;
		if (did == 1) {
			worker = new Employee(id, name, did);
		}
		else if (did == 2) {
			worker = new Manager(id, name, did);
		}
		else {
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();

}
int  WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //���ļ�  ���ļ�

	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//ͳ������
		num++;
	}
	return num;
}


void WorkerManager::Show_Menu() {
	cout << "**************************" << endl;
	cout << "***  ��ӭʹ��ְ������ϵͳ  ***" << endl;
	cout << "*****  0.�˳�����ϵͳ  *****" << endl;
	cout << "*****  1.����ְ����Ϣ  *****" << endl;
	cout << "*****  2.��ʾְ����Ϣ  *****" << endl;
	cout << "*****  3.ɾ����ְԱ��  *****" << endl;
	cout << "*****  4.�޸�ְ����Ϣ  *****" << endl;
	cout << "*****  5.����ְ����Ϣ  *****" << endl;
	cout << "*****  6.���ձ������  *****" << endl;
	cout << "*****  7.��������ĵ�  *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}


//1.���ְ���ĺ���ʵ��
void WorkerManager::Add_Emp() {
	cout << "��������ӵ�ְ��������" << endl;
	int addNum = 0;    //�����û�����������
	cin >> addNum;
	if (addNum > 0) {
		//���
		//��������¿ռ��С
		int newSize = this->m_EmpNum + addNum;  //�¿ռ����� = ԭ����¼������ + ���� ����
		//�����¿ռ�
		Worker ** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;      //ְ�����
			string name; //ְ������
			int dSelect;  //����ѡ��

			cout << "�������" << i + 1 << "����Ա����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "����Ա������" << endl;
			cin >> name;

			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
			case 2:
				worker = new Manager(id, name, 2);
			case 3:
				worker = new Boss(id, name, 3);

			default:
				break;
			}
			//��������ְ��ָ�룬���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		//��ʾ�ɹ����
		cout << "�ɹ����" << addNum << "����ְ��" << endl;
	}
	else {
		cout << "��������" << endl;
	}

	//�������ݵ��ļ���
	this->save();

	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");

}

//�����ļ�
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//������ķ�ʽ���ļ� --д�ļ�
	//��ÿһ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//�ر��ļ�
	ofs.close();

}

//2.��ʾְ��
void WorkerManager::Show_Emp() {
	//�ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��߼�¼Ϊ��" << endl;

	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();

		}
	}
	//�����������
	system("pause");
	system("cls");
}


//�ж�ְ���Ƿ���ڣ�������ڷ���ְ�����������е�λ�ã������ڷ��� -1
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}
//3.ɾ��ְ��
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		//����ְ�����ɾ��
		cout << "��������Ҫɾ��ְ�����" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		//˵��ְ�����ڣ�����Ҫɾ����indexλ���ϵ�ְ��
		if (index != -1) {  
			//����ǰ��
			for (int i= index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;   //���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ����" << endl;
		}
	}
	//�����������
	system("pause");
	system("cls");
}

//4.�޸�ְ��
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������Ҫ�޸ĵ�ְ�����" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			//���ҵ���ŵ�Ա��
			delete this->m_EmpArray[index];
			int NewId;
			string NewName;
			int NewSelect;
			cout << "���ҵ�idΪ" << id << "��ְ��" << endl;
			cout << "�������µ�ְ���ţ�" << endl;
			cin >> NewId;
			cout << "�������µ�ְ��������" << endl;
			cin >> NewName;
			cout << "�������µ�ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> NewSelect;

			Worker* worker = NULL;
			switch (NewSelect)
			{
			case 1:
				break;
				worker = new Employee(NewId, NewName, NewSelect);
			case 2:
				worker = new Manager(NewId, NewName, NewSelect);
				break;
			case 3:
				worker = new Boss(NewId, NewName, NewSelect);
				break;

			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArray[index] = worker;
			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();


		}
		else {
			cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2����ְ����������" << endl;
		int find_way;
		cin >> find_way;
		if (find_way == 1) {
			//��ְ����Ų���
			cout << "������Ҫ���ҵ�ְ����ţ�" << endl;
			int emp_id;
			cin >> emp_id;
			int index = IsExist(emp_id);
			if (index != -1) {
				//�ҵ����ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else if(find_way == 2){
			//��ְ����������
			//��ְ����Ų���
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			string name;
			cin >> name;
			//�����Ƿ�鵽�ı�־
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					//�ҵ����ְ��
					cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "����ʧ�ܣ����޴��ˣ�" << endl;
			}

		}
		else {
			cout << "�����������������룡" << endl;
		}

	}
	//�����������
	system("pause");
	system("cls");
}

//6.����ְ���������
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ķ�ʽ��" << endl;
		cout << "1����ְ���Ž�����������" << endl;
		cout << "2����ְ���Ž��н�������" << endl;
		int select_sort_way;
		cin >> select_sort_way;
		for (int i = 0; i < m_EmpNum; i++) {
			//������Сֵ�������ֵ���±�
			int minormax = i;
			for(int j=i+1;j<this->m_EmpNum;j++){
				if (select_sort_way == 1) {
					//����
					if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minormax = j;
					}

				}
				else if(select_sort_way ==2){
					//����
					//������ǿ�ʼ�϶������ֵ�±� ��С�� ���������±�ֵ
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minormax = j;
					}
				}
				else {
					cout << "�����������������룡" << endl;
				}
			}
			//�ж�һ��ʼ�϶� ��Сֵ�������ֵ �ǲ��Ǽ������Сֵ�����ֵ��������ǵĻ�����������
			if (i != minormax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save();      //�����Ľ�����浽�ļ���
		this->Show_Emp();  //չʾ����Ա��
		
	}
}
//7.����ļ�
void WorkerManager::Clean_Emp() {
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;
	int clean_way;
	cin >> clean_way;
	if (clean_way == 1) {
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc);   //ɾ���ļ����ٴ���
		ofs.close();
		if (this->m_EmpArray != NULL) {
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "��ճɹ�" << endl;

	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0; i < this->m_EmpNum; i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


