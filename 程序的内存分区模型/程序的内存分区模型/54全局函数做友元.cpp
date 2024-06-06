#include<iostream>
#include<string>
using namespace std;


//全局函数做友元

class Building54 {

    //告诉编译器 goodGay全局函数 是 Building类的好朋友，可以访问类中的私有内容  
    friend void goodGay(Building54* building);

public:
    Building54()
    {
        this->m_SittingRoom = "客厅";
        this->m_BedRoom = "卧室";
    }
    string m_SittingRoom;   //客厅

private :
    string m_BedRoom;      // 卧室
};
//全局函数
//全局函数做友元需要再  类  的最开始，做一个  带有关键字 friend 的函数声明
void goodGay(Building54* building) {
    cout << "好基友正在访问公共属性客厅： " << building->m_SittingRoom << endl; 

    //私有属性不可访问
    //想要使好友访问私有属性 
    cout << "好基友正在访问私有属性卧室：" << building->m_BedRoom << endl;
}
void test5401() { 
    Building54 b;
    goodGay(&b); 
}
int main54() {


    test5401();

    system("pause");
    return 0;
}