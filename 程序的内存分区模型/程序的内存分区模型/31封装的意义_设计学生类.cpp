#include<iostream>
#include<string>
using namespace std;

//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
/*
    类中的属性和行为  我们统称为成员
    属性   成员属性  成员变量
    行为   成员函数  成员方法
*/

//class 类名{ 访问权限：属性 / 行为 }；
//class 代表设计一个类，类后面紧跟着的就是类名称
class Student {
    //访问权限
    // 公共权限
public:

    //属性
    //姓名
    string s_name;
    //
    int s_id;
   
    //行为
    //显示姓名和学号
    void showname_id(){
        cout << "姓名: " << s_name << "    学号: " << s_id << endl;
    };

    //通过行为给属性赋值
    void setName(string name) {
        s_name = name;
    };
    void setID(int id)
    {
        s_id = id;

    };

};
int main311() {


    //通过学生类  创建具体的学生（对象）
    //实例化（通过一个类  创建一个对象的过程）
    Student Student007;

    //给学生对象的属性进行赋值
    Student007.s_name = "张三";
    Student007.s_id = 20240411;
    Student007.showname_id();
    Student007.setName("李四");
    Student007.setID(20240412);
    Student007.showname_id();



    




    system("pause");
    return 0;
}