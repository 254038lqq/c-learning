#include<iostream>
#include<string>
using namespace std;
/*
    当类模板碰到继承时，需要注意一下几点：
        当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
        如果不指定，编译器无法给子类分配内存
        如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
template<class T>
class Base011
{
    T m;
};
//class Son:public Base //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son011 :public Base011<int> //必须指定一个类型
{
};
void test01101()
{
    Son011 c;
}


// 如果想灵活指定出父类中T的类型，子类也需变为类模板
// 类模板继承类模板 ,可以用T2指定父类中的T类型
template<class T1, class T2>
class Son0112 :public Base011<T2>
{
public:
    Son0112()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
    T1 obj;

};
void test01102()
{
    Son0112<int, char> child1;
}
int main011() {


    test01102();

    system("pause");
    return 0;
}