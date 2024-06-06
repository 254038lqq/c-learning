#include<iostream>
#include<string>
using namespace std;

//继承中的对象模型
class Base67 {
public: 
    int m_A; 
protected: 
    int m_B; 
private: 
    int m_C; //私有成员只是被隐藏了，但是还是会继承下去
};
//公共继承 
class Son67 :public Base67 { 
public: 
    int m_D; 
};
void test6701() { 
    //父类中所有的非静态成员属性都会被子类继承下去
    //父类中的私有成员属性 是被编译器给隐藏了，因此是访问不到，但是确实被继承下去了
    cout << "sizeof Son = " << sizeof(Son67) << endl; 
}
//
//cl /d1 reportSingleClassLayout查看的类名 所属文件名
int main67() {


    test6701();

    system("pause");
    return 0;
}