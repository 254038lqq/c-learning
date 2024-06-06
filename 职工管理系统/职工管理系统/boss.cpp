#include"boss.h"

//加上作用域  Employee::

// 构造函数的实现
Boss::Boss(int id, string name, int did) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = did;

}
//显示个人信息 
void Boss::showInfo() {
	cout << "职工编号：" << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t岗位: " << this->getDeptName()
		<< "\t岗位职责： 管理公司所有的事务" << endl;

}
//获取岗位名称
string Boss::getDeptName() {
	return string("总裁");
}