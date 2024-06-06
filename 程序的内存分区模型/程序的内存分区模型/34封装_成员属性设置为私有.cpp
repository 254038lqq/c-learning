#include<iostream>
#include<string>
using namespace std;
/*
    成员属性设置为私有
    优点1：将所有成员属性设置为私有，可以自己控制读写权限
    优点2：对于写权限，我们可以检测数据的有效性
*/
class Preson34 {

public:
    //设置姓名
    void setName(string name) {
        p_name = name;
    }
    //获取姓名
     string getName() {
        return p_name;
    }
     //获取年龄
     int getAge() {
         return p_age;
     }

     //设置偶像
     void setIdol(string idol) {
         p_odol = idol;
     }

private:
    string  p_name;   //姓名 可读可写   
    int p_age =18;       //年龄  只读
    string p_odol;   //偶像  只写
};


int main34() {
    Preson34 p007;
    //姓名设置
    //p007.p_name = "李四";  //私有属性不可访问

    //设置姓名   可读可写
    //写
    p007.setName("张三");
    //读
    cout << " 姓名： " << p007.getName() << endl;

    //只读
    p007.getAge();
    cout <<"p007.getAge():"<< p007.getAge() << endl;

    //只写   读不到
    p007.setIdol("胡歌");   

    system("pause");
    return 0;
}