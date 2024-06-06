#include<iostream>
#include<string>
using namespace std;

//继承方式


class Base661 { 
public: 
    int m_A;
protected: 
    int m_B; 
private: 
    int m_C; 
};
//公共继承 
class Son661 :public Base661 { 
public: 
    void func() { 
        m_A = 10;  //可访问public权限              父类中的公共权限成员  到子类中依然是公共权限
        m_B = 10; //可访问 protected权限           父类中的保护权限成员 到子类中依然是保护权限
        //m_C = 10; //不可访问                     父类中的私有权限成员  子类中不管是什么权限都访问不到
    } 
};
void myClass661() {
    Son661 s661; 
    s661.m_A = 100;    //公共权限：类内可以访问，类外也可以访问
    //s661.m_B = 110;  //不可访问  保护权限：类内可以访问，类外不可以访问
}

//保护继承 
class Son662:protected Base661{ 
public: 
    void func() {
        m_A = 100; //可访问protected权限     父类中的公共权限成员  到子类中变成保护权限
        m_B = 100; //可访问protected权限     父类中的保护权限成员  到子类中依然是保护权限
        //m_C; //不可访问    父类中的私有权限成员  子类中不管是什么权限都访问不到
    } 
}; 
void myClass662() {
            Son662 s662; //
            //s.m_A; //不可访问  在保护继承中，   父类中的公共权限成员  到子类中变成保护权限，因此类外访问不到
}
//私有继承 
class Son663:private Base661{ 
public: 
    void func() {
                m_A = 110; //可访问private权限                 父类中的公共权限成员  到子类中变成私有权限成员
                m_B = 100; //可访问private权限//               父类中的保护权限成员  到子类中变成私有权限成员
                //m_C; //不可访问         父类中的私有权限成员  子类中不管是什么权限都访问不到
                } 
}; 
void myClass663() {
    Son663 s663;
    // Son3是私有继承，所以继承Son3的属性在GrandSon3中都无法访问到
    //s663.m_A = 100;    
    //s661.m_B = 110;  
}

class Grandson3 :public Son663 {
public:
    void func() {    
        // m_A = 100;  
        // m_B = 100;
    }
};
int main66() {




    system("pause");
    return 0;
}