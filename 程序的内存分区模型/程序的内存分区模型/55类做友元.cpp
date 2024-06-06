#include<iostream>
#include<string>
using namespace std;


//类做友元

//与函数声明类似。。。类的声明，提前告诉编译器有这个类
class Building55; 

class goodGay {
public:
    goodGay();
    void visit();  //参观函数  访问 Building 中的属性
private: 
    Building55* building;
};

class Building55 { 
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容 
    friend class goodGay;
//行为--成员函数--成员方法--构造函数
public: 
    Building55();

//属性 -- 成员属性---成员变量--
public: 
    string m_SittingRoom; //客厅
private: 
    string m_BedRoom;//卧室 
};

//类外实现成员函数
//加作用域 告诉它是 Building  下的成员函数
Building55::Building55() { 
    this->m_SittingRoom = "客厅"; 
    this->m_BedRoom = "卧室"; 
}

goodGay::goodGay() { 
    //创建一个建筑物的对象
    building = new Building55; 
}
void goodGay::visit() {
     cout << "好基友正在访问" << building->m_SittingRoom << endl; 
     cout << "好基友正在访问" << building->m_BedRoom << endl; 
}
void test5501() {
    //实例化对象  创建了一个类别为 goodGay 的对象 gg
    goodGay gg; 
    //调用  goodGay类的 visit() 函数
    gg.visit();
}
int main55() {

    test5501();

    system("pause");
    return 0;
}