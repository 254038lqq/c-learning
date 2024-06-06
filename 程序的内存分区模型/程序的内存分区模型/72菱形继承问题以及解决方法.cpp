#include<iostream>
#include<string>
using namespace std;

//菱形继承问题已经解决方法
 class Animal72 { 
 public: 
     int m_Age; 
 };
//继承前加virtual关键字后，变为虚继承 
//此时公共的父类Animal称为虚基类 
class Sheep72 : virtual public Animal72{
};
class Tuo72 : virtual public Animal72 {
}; 
class SheepTuo72 : public Sheep72, public Tuo72 {
};

void test7201() {
    SheepTuo72 st72; 
    st72.Sheep72::m_Age = 100; 
    st72.Tuo72::m_Age = 200;
    //当菱形继承，两个父类拥有相同数据，需要加作用域加以区分
    cout << "st.Sheep::m_Age = " << st72.Sheep72::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st72.Tuo72::m_Age << endl;
    // 这份数据我们知道有一份就可以了，菱形继承导致数据有两份，资源浪费
    // 利用虚继承 解决菱形继承的问题

    cout << "st.m_Age = " << st72.m_Age << endl;
}
int main72() {
    test7201();
    system("pause");
    return 0;
}