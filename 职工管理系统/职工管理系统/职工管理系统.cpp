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

	//测试代码
	//Worker* worker= NULL;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Manager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	// ctrl + K ,ctrl + c 多行注释
	// ctrl +k,ctrl + u 
	//创建一个管理类的对象
	WorkerManager wm;
	int choise = 0;
	while (true) {
		wm.Show_Menu();
		cout << "请输入您的选择： " << endl;
		cin >> choise;   // 接受用户的选择
		switch (choise)
		{
		case 0:   //退出系统
			wm.exitSystem();
			break;
		case 1:   //添加职工
			wm.Add_Emp();
			break;
		case 2:  //显示职工
			wm.Show_Emp();
			break;
		case 3:  //删除职工
		//{
		//	//测试
		//	int ret = wm.IsExist(1);
		//	if (ret != -1) {
		//		cout << "职工存在" << endl;
		//	}
		//	else {
		//		cout << "职工不存在" << endl;
		//	}

		//	break;
		//}
			wm.Del_Emp();
			break;
		case 4:   //修改职工
		{
			wm.Mod_Emp();
			break; 
		}
		case 5:   //查找职工
			wm.Find_Emp();
			break;
		case 6:  //排序职工
			wm.Sort_Emp();
			break;
		case 7:  //清空文档
			wm.Clean_Emp();
			break;
		default:
			system("cls");  //清屏
			break;
		}

	}


	system("pause");  //请安任意键继续
	return 0;
}