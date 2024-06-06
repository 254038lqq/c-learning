#include<iostream>
#include<string>
using namespace std;

//结构体数组
//1.定义结构体
struct Student {
    //成员列表
    //姓名
    string name;
    //年龄
    int age;
    //分数
    int score;
};

int main20() {
    //2. 创建结构体数组
    struct Student stuarr[3] = {
        {"张三",19,100},
        {"李四", 17, 98},
        {"王五", 13, 196},
    };


    //3. 给 结构体数组中的元素赋值 ，
    stuarr[2].name = "赵六";
    stuarr[2].age = 18;
    stuarr[2].score = 98;

    //4.遍历结构体数组
    for (int i = 0; i < 3; i++) {
        cout << "  姓名： " << stuarr[i].name
             << "  年龄： " << stuarr[i].age
             << "  分数： " << stuarr[i].score << endl;
    }
    system("pause");
    return 0;
}