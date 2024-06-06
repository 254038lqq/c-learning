#include "workerManager.h"

//构造函数的空实现
WorkerManager::WorkerManager(){
	//初始化属性
	//分三种情况初始化
	//1、文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //读文件
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;        //初始化人数为0
		this->m_EmpArray = NULL;   //初始化数组指针为空
		this->m_FileIsEmpty = true;  //初始化文件为空
		ifs.close();
		return;
	}
	//2.文件存在但数据位空
	//	打开文件时，文件状态标识是初始化状态，eof()函数是根据文件状态标识来判断当前是否是文件尾，而不是判断文件是否为空。
	// 当读取文件数据时，遇到文件尾时，系统会更改文件状态标识为文件尾，返回EOF标志。
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件为空
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;        //初始化人数为0
		this->m_EmpArray = NULL;   //初始化数组指针为空
		this->m_FileIsEmpty = true;  //初始化文件为空
		ifs.close();
		return;
	}
	//当文件存在，并且不为空时
	int num = this->get_EmpNum();
	//cout << "职工人数为： " << num << endl;;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中的数据 存到数组中
	this->init_Emp();

	//测试代码
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "员工编号： " << this->m_EmpArray[i]->m_Id << "  员工姓名：" << this->m_EmpArray[i]->m_Name
	//		<< "  员工部门：" << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

//初始化员工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件  读文件
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
	//关闭文件
	ifs.close();

}
int  WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in); //打开文件  读文件

	int id;
	string name;
	int did;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did) {
		//统计人数
		num++;
	}
	return num;
}


void WorkerManager::Show_Menu() {
	cout << "**************************" << endl;
	cout << "***  欢迎使用职工管理系统  ***" << endl;
	cout << "*****  0.退出管理系统  *****" << endl;
	cout << "*****  1.增加职工信息  *****" << endl;
	cout << "*****  2.显示职工信息  *****" << endl;
	cout << "*****  3.删除离职员工  *****" << endl;
	cout << "*****  4.修改职工信息  *****" << endl;
	cout << "*****  5.查找职工信息  *****" << endl;
	cout << "*****  6.按照编号排序  *****" << endl;
	cout << "*****  7.清空所有文档  *****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem() {
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}


//1.添加职工的函数实现
void WorkerManager::Add_Emp() {
	cout << "请输入添加的职工的数量" << endl;
	int addNum = 0;    //保存用户的输入数量
	cin >> addNum;
	if (addNum > 0) {
		//添加
		//计算添加新空间大小
		int newSize = this->m_EmpNum + addNum;  //新空间人数 = 原来记录的人数 + 新增 人数
		//开辟新空间
		Worker ** newSpace = new Worker * [newSize];

		//将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;      //职工编号
			string name; //职工姓名
			int dSelect;  //部门选择

			cout << "请输入第" << i + 1 << "个新员工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新员姓名：" << endl;
			cin >> name;

			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//将创建的职工指针，保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		//提示成功添加
		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else {
		cout << "输入有误！" << endl;
	}

	//保存数据到文件中
	this->save();

	//按任意键后 清屏回到上级目录
	system("pause");
	system("cls");

}

//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用输出的方式打开文件 --写文件
	//将每一个人的数据写入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	//关闭文件
	ofs.close();

}

//2.显示职工
void WorkerManager::Show_Emp() {
	//判断文件是否为空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者记录为空" << endl;

	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			//利用多态调用程序接口
			this->m_EmpArray[i]->showInfo();

		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}


//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回 -1
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
//3.删除职工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		//按照职工编号删除
		cout << "请输入想要删除职工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		//说明职工存在，并且要删除掉index位置上的职工
		if (index != -1) {  
			//数据前移
			for (int i= index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;   //更新数组中记录人员个数
			//数据同步更新到文件中
			this->save();
			cout << "删除成功！" << endl;
		}
		else {
			cout << "删除失败，未找到该职工！" << endl;
		}
	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//4.修改职工
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入想要修改的职工编号" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			//查找到编号的员工
			delete this->m_EmpArray[index];
			int NewId;
			string NewName;
			int NewSelect;
			cout << "查找到id为" << id << "的职工" << endl;
			cout << "请输入新的职工号：" << endl;
			cin >> NewId;
			cout << "请输入新的职工姓名：" << endl;
			cin >> NewName;
			cout << "请输入新的职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
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
			//更新数据到数组中
			this->m_EmpArray[index] = worker;
			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();


		}
		else {
			cout << "修改失败，查无此人！" << endl;
		}
	}

	//按任意键清屏
	system("pause");
	system("cls");
}
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
	}
	else {
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按职工姓名查找" << endl;
		int find_way;
		cin >> find_way;
		if (find_way == 1) {
			//按职工编号查找
			cout << "请输入要查找的职工编号：" << endl;
			int emp_id;
			cin >> emp_id;
			int index = IsExist(emp_id);
			if (index != -1) {
				//找到这个职工
				cout << "查找成功！该职工的信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else {
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else if(find_way == 2){
			//按职工姓名查找
			//按职工编号查找
			cout << "请输入要查找的职工姓名：" << endl;
			string name;
			cin >> name;
			//加入是否查到的标志
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					//找到这个职工
					cout << "查找成功！该职工的信息如下：" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "查找失败，查无此人！" << endl;
			}

		}
		else {
			cout << "输入有误，请重新输入！" << endl;
		}

	}
	//按任意键清屏
	system("pause");
	system("cls");
}

//6.按照职工编号排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请选择排序的方式：" << endl;
		cout << "1、按职工号进行升序排序" << endl;
		cout << "2、按职工号进行降序排序" << endl;
		int select_sort_way;
		cin >> select_sort_way;
		for (int i = 0; i < m_EmpNum; i++) {
			//声明最小值或者最大值的下标
			int minormax = i;
			for(int j=i+1;j<this->m_EmpNum;j++){
				if (select_sort_way == 1) {
					//升序
					if (this->m_EmpArray[minormax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minormax = j;
					}

				}
				else if(select_sort_way ==2){
					//降序
					//如果我们开始认定的最大值下标 还小于 遍历到的下标值
					if (this->m_EmpArray[minormax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minormax = j;
					}
				}
				else {
					cout << "输入有误，请重新输入！" << endl;
				}
			}
			//判断一开始认定 最小值或者最大值 是不是计算的最小值或最大值，如果不是的话，交换数据
			if (i != minormax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minormax];
				this->m_EmpArray[minormax] = temp;
			}
		}
		cout << "排序成功！排序后的结果为：" << endl;
		this->save();      //排序后的结果保存到文件中
		this->Show_Emp();  //展示所有员工
		
	}
}
//7.清空文件
void WorkerManager::Clean_Emp() {
	cout << "确定清空？" << endl;
	cout << "1、确定" << endl;
	cout << "2、返回" << endl;
	int clean_way;
	cin >> clean_way;
	if (clean_way == 1) {
		//清空文件
		ofstream ofs(FILENAME, ios::trunc);   //删除文件后再创建
		ofs.close();
		if (this->m_EmpArray != NULL) {
			//删除堆区的每个职工对象
			for (int i = 0; i < this->m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//删除堆区数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;

		}
		cout << "清空成功" << endl;

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


