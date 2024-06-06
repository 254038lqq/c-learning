#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
#include<ctime>

#define CEHUA 0
#define MEISHU 1
#define YANFA 2

//公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
//员工信息有 : 姓名 工资组成；部门分为：策划、美术、研发
//随机给10名员工分配部门和工资
//通过multimap进行信息的插入 key(部门编号) value(员工)
//分部门显示员工信息
class worker65 {
public:
	string m_name;
	int m_Salary;
};
void createWorker(vector<worker65> &v) {
	string nameseed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++) {
		worker65 worker;
		worker.m_name = "员工";
		worker.m_name += nameseed[i];

		//int num = rand() % n + a;
		//其中的a是起始值，n - 1 + a是终止值，n是整数的范围。
		worker.m_Salary = rand() % 10000 + 10000; //10000 ~ 19999

		//将员工放入到容器中
		v.push_back(worker);
	}
}
//员工分组的实现
void setGroup(vector<worker65> &vw,multimap<int,worker65> &mw) {
	for (vector<worker65>::iterator it = vw.begin(); it != vw.end(); it++) {
		//产生随机部门编号
		int depart_id = rand() % 3;   // 0 ,1,2
		//将员工插入到分组中
		mw.insert(make_pair(depart_id,*it));
	}
}

//
void showWorkerByGroup(multimap<int ,worker65> &mw) {
	cout << "策划部门：" << endl;
	multimap<int,worker65>::iterator pos = mw.find(CEHUA);
	int count = mw.count(CEHUA);
	int index = 0;
	for (; pos != mw.end() &&  index <count ; pos++,index++) {
		cout << "姓名： " << pos->second.m_name << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "=================================================" << endl;
	cout << "美术部门：" << endl;
	pos = mw.find(MEISHU);
	count = mw.count(MEISHU);
	index = 0;
	for (; pos != mw.end() && index < count; pos++, index++) {
		cout << "姓名： " << pos->second.m_name << "工资：" << pos->second.m_Salary << endl;
	}

	cout << "=================================================" << endl;
	cout << "研发部门：" << endl;
	pos = mw.find(YANFA);
	count = mw.count(YANFA);
	index = 0;
	for (; pos != mw.end() && index < count; pos++, index++) {
		cout << "姓名： " << pos->second.m_name << "工资：" << pos->second.m_Salary << endl;
	}
}
int main065() {
	srand((unsigned int)time(NULL));
	//1.创建员工
	vector<worker65> vworker;
	createWorker(vworker);

	////阶段测试
	//for (vector<worker65>::iterator it = vworker.begin(); it != vworker.end(); it++) {
	//	cout << "姓名: " << it->m_name << "\t工资: " << it->m_Salary << endl;

	//}

	//2.员工分组
	multimap<int,worker65> mworker;
	setGroup(vworker,mworker);

	//分组显示员工
	showWorkerByGroup(mworker);
	system("pause");
	return 0;
}