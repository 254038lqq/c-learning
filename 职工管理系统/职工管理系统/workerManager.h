#pragma once        //防止头文件重复包含
#include<iostream>  //包含输入出输出流文件
using namespace std;  //使用标准的命名空间
#include"worker.h"
#include"boss.h"
#include"manager.h"
#include"employee.h"

#include<fstream>
#define FILENAME "empFile.txt"
// 类的声明
class WorkerManager {
public:
	//构造函数
	WorkerManager();
	//展示菜单
	void Show_Menu();
	//0.退出管理系统
	void exitSystem();
	
	// 记录职工人数
	int m_EmpNum;
	// 职工数组指针
	Worker** m_EmpArray;

	//1.添加职工
	void Add_Emp();

	//保存文件
	void save();

	//判断文件是否为空的标志
	bool m_FileIsEmpty;
	//统计文件中的人数；
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//2.显示职工
	void Show_Emp();

	//3.删除职工
	void Del_Emp();

	//判断职工是否存在，如果存在返回职工所在数组中的位置，不存在返回 -1
	int IsExist(int id);

	//4.修改职工
	void Mod_Emp();
	//5.查找职工
	void Find_Emp();

	//6.按照职工编号排序
	void Sort_Emp();

	//7.清空文件
	void Clean_Emp();
	//析构函数
	~WorkerManager();

};