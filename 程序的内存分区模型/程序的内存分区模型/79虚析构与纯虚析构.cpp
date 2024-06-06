#include<iostream>
#include<string>
using namespace std;
//虚析构与纯虚析构

class Animal79 {
public:
    Animal79()
    {
        cout << "Animal 构造函数调用！" << endl;
    }
    //纯虚函数
    virtual void Speak() = 0;
    //析构函数加上virtual关键字，变成虚析构函数
    //virtual ~Animal79()
    // {
    //     cout << "Animal虚析构函数调用！" << endl;
    //}
    //纯虚析构   需要声明  也需要有实现
    // 有了纯虚析构之后，这个类也属于抽象类，无法实例化
    virtual ~Animal79() = 0;
};
Animal79::~Animal79() { 
    cout << "Animal 纯虚析构函数调用！" << endl; 
}
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。
class Cat79 : public Animal79 {
public: 
    Cat79(string name) {
        cout << "Cat构造函数调用！" << endl; 
        //数据创建到堆区，new string  返回的是一个 string 类型的指针，使用创建的  string类型指针     string* m_Name;  去维护
        m_Name = new string(name);
    }   
    virtual void Speak() { 
        cout << *m_Name << "小猫在说话!" << endl; 
    } 
    //在cat的析构函数中，应该将在堆区创建的数据   string name  给释放干净
    ~Cat79() {
        
        if (this->m_Name != NULL) { 
            cout << "Cat析构函数调用!" << endl;
            delete m_Name; 
            m_Name = NULL; 
        }
    }
public: 
    //加一个代表猫属性的指针
    string* m_Name;
};
void test7901() {
    //父类指针指向子类对象
    Animal79* animal = new Cat79("Tom"); 
    animal->Speak();
    //父类指针在析构的时候，不会调用子类中析构函数，导致子类中如果有堆区属性，出现内存泄漏
    //通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
    //怎么解决？给基类增加一个虚析构函数
    //虚析构函数就是用来解决通过父类指针释放子类对象
    delete animal;
}
int main79() {

    test7901();


    system("pause");
    return 0;
}