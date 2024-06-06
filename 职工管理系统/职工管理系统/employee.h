#pragma once
//普通员工的头文件
#include<iostream>
#include<string>
using namespace std;

#include "worker.h"

class Employee : public Worker {
public:
	//构造函数  每个员工在构造时，应该初始化他身上的属性
	Employee(int id, string name,int did);
	//显示个人信息
	virtual void showInfo();
	//获取岗位名称
	virtual string getDeptName();
};