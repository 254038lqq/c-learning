#pragma once
#include<iostream>
#include<string>
using namespace std;

//职工抽象类
class Worker{
public:
	//行为  成员函数
	//显示个人信息
	// 函数前面加上virtual关键字，变成虚函数, 后面加 = 0 变成纯虚函数，有纯虚函数的类叫做抽象类
	virtual void showInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;

	//成员属性
	//职工编号
	int m_Id;
	//职工姓名
	string m_Name;
	//部门编号
	int m_DeptId;

};
