#include<iostream>
#include<string>
using namespace std;

//多态
class Animal75 {
public: 
    //Speak函数就是虚函数 
    //函数前面加上virtual关键字，变成虚函数，那么编译器在编译的时候就不能确定函数调用了。
    virtual void speak75() {
        cout << "动物在说话" << endl; 
    }
};
class Cat75 :public Animal75 { 
public: 
    void speak75() { 
        cout << "小猫在说话" << endl; 
    } 
};
class Dog75 :public Animal75 {
public:
    void speak75()
    {
        cout << "小狗在说话" << endl;
    }
}; 
//我们希望传入什么对象，那么就调用什么对象的函数 
// //如果函数地址在编译阶段就能确定，那么静态联编 
// //如果函数地址在运行阶段才能确定，就是动态联编
// Animal75 & animal = cat
//执行说话的函数的时候
// 地址早绑定  在编译阶段确定函数地址    所以Cat75 cat; DoSpeak75(cat);  两句执行时输出的是动物在说话而不是小猫在说话
//如果想执行让猫说话，那么函数地址就不能提前绑定，需要在运行阶段进行绑定，地址晚绑定
void DoSpeak75(Animal75& animal) { 
    animal.speak75(); 
} 
//动态多态满足条件： 
// //1、有继承关系 
// //2、子类重写父类中的虚函数 
//多态使用： 
// //父类指针或引用指向子类对象
void test7501() {
    Cat75 cat; 
    DoSpeak75(cat);
    Dog75 dog;
    DoSpeak75(dog);
}
void tets7502() {
    //32位（X86）指针是4个字节   64位指针是8个字节
    cout << "sizeof animal = " << sizeof(Animal75) << endl;
}
int main75() {
   // test7501();
    tets7502();
    system("pause");
    return 0;
}