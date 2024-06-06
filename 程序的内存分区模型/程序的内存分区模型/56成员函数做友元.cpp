#include<iostream>
#include<string>
using namespace std;

//成员函数做友元
// 
////与函数声明类似。。。类的声明，提前告诉编译器有这个类
class Building56; 

class goodGay56 {
public:
    //构造函数
    goodGay56();
    //成员函数--成员方法
    void visit(); //只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2();
private: 
    //声明一个 Building56 类型的指针
    Building56* building;
};
class Building56 { 
    //告诉编译器 goodGay类中的visit成员函数 是Building好朋友，可以访问私有内容 
    friend void goodGay56::visit();
public: 
    //构造函数
    Building56();
public: 
    string m_SittingRoom; //客厅
    private: string m_BedRoom;//卧室 
};

//类外实现成员函数
Building56::Building56() { 
    this->m_SittingRoom = "客厅"; 
    this->m_BedRoom = "卧室"; 
}
goodGay56::goodGay56() { 
    //使用了new关键字来动态地在堆（heap）中分配内存空间，以存储一个Building56类的实例，并将该实例的地址赋值给了building指针变量。
    building = new Building56; 
}
void goodGay56::visit() {
    cout << "好基友visit正在访问" << building->m_SittingRoom << endl; 
    cout << "好基友visit正在访问" << building->m_BedRoom << endl; 
}
void goodGay56::visit2() {
    cout << "好基友visit2正在访问" << building->m_SittingRoom << endl; 
    //cout << "好基友正在访问" << building->m_BedRoom << endl; 
}
void test5601() {
    goodGay56 gg; 
    gg.visit();
}
int main56() {


    test5601();

    system("pause");
    return 0;
}