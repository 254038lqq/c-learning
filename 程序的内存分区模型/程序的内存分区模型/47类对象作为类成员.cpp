#include<iostream>
#include<string>
using namespace std;

//B类中有对象A作为成员，A为对象成员
//那么当创建B对象时，A与B的构造和析构的顺序是谁先谁后？

//手机类
class Phone47 {  
public:
    Phone47(string pname) {
        cout <<   "Phone47 构造函数调用" <<  endl;
        phone_name = pname;
    }
    ~Phone47() {
        cout << "Phone47 析构函数调用" << endl;
    }

    //手机品牌
    string phone_name;
};

//人 类
class person47 {
public:
    person47(string name,string pname):p_name(name), p_phone(pname){
        cout << "person47 构造函数调用" << endl;
    }
    ~person47() {
        cout << "person47 析构函数调用" << endl;
    }
    //姓名
    string p_name;
    //手机
    Phone47 p_phone;
};
//当其他类作为本类成员，构造时先构造类对象，再构造自身
//析构的顺序与构造顺序相反
void test47()
{
    person47 p47("张三", "苹果15max");
    cout << p47.p_name << "拿着" << p47.p_phone.phone_name << endl;
}
int main47() {

    test47();


    system("pause");
    return 0;
}