#include<iostream>
#include<string>
using namespace std;

#define MAX 1000
//• 封装函数显示该界面 如 void showMenu()
//• 在main函数中调用封装好的函数
//1.菜单界面
void showMenu() {
	cout << "**************************" << endl;
	cout << "*****  1.添加联系人  *****" << endl;
	cout << "*****  2.显示联系人  *****" << endl;
	cout << "*****  3.删除联系人  *****" << endl;
	cout << "*****  4.查找联系人  *****" << endl;
	cout << "*****  5.修改联系人  *****" << endl;
	cout << "*****  6.清空联系人  *****" << endl;
	cout << "*****  0.退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
//1.添加联系人
/*
* 功能描述：
	实现添加联系人功能，联系人上限为1000人，联系人信息包括（姓名、性别、年龄、联系电话、家庭住址）
添加联系人实现步骤：
	• 设计联系人结构体
	• 设计通讯录结构体
	• main函数中创建通讯录
	• 封装添加联系人函数
	• 测试添加联系人功能
*/
//联系人结构体
struct Person {
	string m_Name;
	int m_Sex;  //1.男 2.女
	int m_Age;
	string m_Phone;
	string m_Addr;
};
//通讯录结构体
struct Addressbooks {
	//通讯录中保存联系人数组
	struct Person personArray[MAX];
	//通讯录中当前记录联系人个数
	int m_Size;
};
void addperson(Addressbooks* abs) {
	//判断通讯录是否已满，如果满了，就不再条件
	if (abs->m_Size == MAX) {
		cout << "通讯录已满，无法添加" <<endl;
	}
	else {
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		int sex = 0;
		while (true) {

			//如果输入的是1或者是2，可以退出循环，因为输入的是正确值.
			//如果输入的有误，请重新输入
			cout << "请输入性别： " << endl;
			cout << "1 ---- 男" << endl;
			cout << "2 ---- 女" << endl;
		
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误，请重新输入！" << endl;
			}

		}

		//年龄
		int age = 0;
		while (true) {
			cout << "请输入年龄： " << endl;
			cin >> age;
			if (age >= 0 && age <= 100) {
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//联系电话
		cout << "请输入联系电话" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//联系电话
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//更新通讯录的人数
		abs->m_Size += 1;

		cout << "添加成功" << endl;
		
		system("pause");  //请安任意键继续
		system("cls");    //清屏操作

	}

}
//2.显示联系人
void showperson(Addressbooks* abs){
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0) {
		cout << "当前记录为空！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			//cout << "姓名： " << abs->personArray[i].m_Age << "  性别：" << abs->personArray[i].m_Sex << "  年龄： " << abs->personArray[i].m_Age << "  电话： " << abs->personArray[i].m_Phone << "  住址： " << abs->personArray[i].m_Addr << endl;
			cout << "姓名： " << abs->personArray[i].m_Name <<  "\t";
			cout << "性别： " << (abs->personArray[i].m_Sex ==1 ? "男":"女") << "\t";
			cout << "年龄： " << abs->personArray[i].m_Age << "\t";   // \t 水平制表符  ，空 8 个字节的位置
			cout << "电话： " << abs->personArray[i].m_Phone << "\t";
			cout << "住址： " << abs->personArray[i].m_Addr << endl;

		}
		system("pause");  //请安任意键继续
		system("cls");    //清屏操作
	}

}
//检测联系人是否存在，如果存在，返回联系人所在数组中的具体位置，不存在返回 -1
//参数1 通讯录 参数2 对比姓名
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personArray[i].m_Name == name) {
			return i;     //如果找到了，返回这个人在数组中的地址
		}
	}
	return -1;    //如果遍历结束都没有找到，返回-1

}
//3.删除联系人
void delperson(Addressbooks* abs) {
	cout << "请输入您要删除的联系人的姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//找到这个人的下标 ret
		for (int i = ret; i < abs->m_Size; i++) {
			abs->personArray[i] = abs->personArray[i + 1];
		}
		//更新通讯录中的人员数
		abs->m_Size--;
		cout << "删除成功！" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");

}

//4.查找联系人
void findperson(Addressbooks* abs) {
	cout << "请输入您要查找的联系人的姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//找到这个人的下标 ret
		cout << "姓名： " << abs->personArray[ret].m_Name<< "\t";
		cout << "性别： " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personArray[ret].m_Age << "\t";   // \t 水平制表符  ，空 8 个字节的位置
		cout << "电话： " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址： " << abs->personArray[ret].m_Addr << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(Addressbooks* abs) {
	cout << "请输入您要修改的联系人的姓名： " << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		cout << "请输入性别：" << endl;
		cout << "1 - - 男" << endl;
		cout << "2 -- 女" << endl;
		//性别
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//联系电话
		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//家庭住址
		cout << "请输入家庭住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;
	}
	else {
		cout << "查无此人！" << endl;
	}
	system("pause");
	system("cls");
}
void cleraperson(Addressbooks* abs) {
	abs->m_Size = 0; cout << "通讯录已清空" << endl; system("pause"); system("cls");
}
int main() {

	//创建通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;
	//创建一个用户选择输入的变量
	int select = 0;
	//菜单调用
	
	while (true) {
		showMenu();
		cout << "请选择功能键：" << endl;
		cin >> select;
		switch (select) {
		case 1:     //1.添加联系人
			addperson(&abs);    //利用地址传递可以可以修饰实参
			break;
		case 2:     //2.显示联系人
			showperson(&abs);
			break;
		case 3:     //3.删除联系人 
			//{
			//	cout << "请输入删除联系人姓名 " << endl;
			//	string name;
			//	cin >> name;
			//	if (isExist(&abs, name) == -1) {
			//		cout << "查无此人！" << endl;
			//	}
			//	else {
			//		cout << "找到此人！" << endl;
			//	}
			//}

			delperson(&abs);
			break;
		case 4:     //4.查找联系人
			findperson(&abs);
			break;
		case 5:     //5.修改联系人
			modifyperson(&abs);
			break;
		case 6:     //6.清空联系人
			cleraperson(&abs);
			break;
		case 0:     //0.退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}

	}

	system("pause");
	return 0;
}