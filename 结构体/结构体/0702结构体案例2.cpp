/*
* ================= 案例描述 ======================
* 设计一个英雄的结构体，包括成员姓名、年龄、性别；创建结构体数组，数组中存放5名英雄。
* 通过冒泡排序算法，将数组中的英雄按照按照年龄进行升序排序，最终打印排序后的结果
* 5名英雄信息如下：
*	{"刘备",23,"男"}
*	{"关羽",22,"男"}
*	{"张飞",20,"男"}
*	{"赵云",21,"男"}
*	{"貂蝉",19,"女"}
* 
* 
*	在C++中，数组名传递给函数时，实际上是传递了数组的首地址。因此，在函数内部，您可以将数组视为一个指针，通过该指针可以访问数组的元素。
*/

#include<iostream>
using namespace std;
#include<string>

//1.定义英雄结构体
struct hero {
	string name;
	int age;
	string gender;
};

//冒泡排序
void bubble_sort(struct hero heroarray[], int len) {
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-i-1; j++) {
			if (heroarray[j].age > heroarray[j+1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
};

void bubble_sort2(struct hero* heroarray, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			
			if (heroarray[j].age > heroarray[j + 1].age) {
				struct hero temp = heroarray[j];
				heroarray[j] = heroarray[j + 1];
				heroarray[j + 1] = temp;
			}
		}
	}
}
int main0702(){
	//2.创建数组存放5名英雄
	struct hero hero_array[5] = {
		{"刘备",23,"男"},
		{"关羽",22,"男"},
		{"张飞",20,"男"},
		{"赵云",21,"男"},
		{"貂蝉",19,"女"}
	};
	int len_h = sizeof(hero_array) / sizeof(hero_array[0]);
	//打印排序前
	cout << "============== 打印排序前数据：==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "姓名：" << hero_array[l].name << "   性别：" << hero_array[l].gender << "   年龄：" << hero_array[l].age << endl;
	};
	//对数组进行排序，按照年龄进行升序排序
	//在C++中，数组名传递给函数时，实际上是传递了数组的首地址。
	bubble_sort(hero_array, len_h);
	//打印排序前
	cout << "============== 打印排序后数据：==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "姓名：" << hero_array[l].name << "   性别：" << hero_array[l].gender << "   年龄：" << hero_array[l].age << endl;
	};
	bubble_sort2(hero_array, len_h);
	//打印排序前
	cout << "============== 打印排序2后数据：==================" << endl;
	for (int l = 0; l < len_h; l++) {
		cout << "姓名：" << hero_array[l].name << "   性别：" << hero_array[l].gender << "   年龄：" << hero_array[l].age << endl;
	};
	system("pause");
	return 0;

}