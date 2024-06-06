#include<iostream>
#include<string>
using namespace std;

//继承中的构造和析构顺序

class Base68 {
public: 
    Base68() {
        cout << "Base构造函数!" << endl; 
    } 
    ~Base68() {
        cout << "Base析构函数!"<< endl;
    }
};
class Son68 : public Base68 {
public: 
    Son68() {
        cout << "Son构造函数!" << endl; 
    } 
    ~Son68() {
        cout << "Son析构函数!" << endl; 
    }
};

void test6801() { 
    //Base68 B68;
    //继承中 先调用父类构造函数，再调用子类构造函数，析构顺序与构造相反 
    Son68 s68; 
}

int main68() {

    test6801();
    system("pause");
    return 0;
}