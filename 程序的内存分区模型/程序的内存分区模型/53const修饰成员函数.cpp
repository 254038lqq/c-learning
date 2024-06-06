#include<iostream>
#include<string>
using namespace std;

//const  修饰成员函数
/*
    常函数：
        成员函数后加const后我们称为这个函数为常函数
        常函数内不可以修改成员属性
        成员属性声明时加关键字mutable后，在常函数中依然可以修改
    常对象：
        声明对象前加const称该对象为常对象
        常对象只能调用常函数
*/
class person53 {
public:
    //行为--成员函数--成员方法--构造函数
    // 
    //这种是可以修改的
    /*
    void showperson() {
        m_A = 100;
    }
    */

    void func53(){
        cout << "我是一个普通的成员函数" << endl;
    }

    // 常函数  在成员函数后面加 const 
    //这个时候 修改成员属性的值就会报错
    // 在成员函数后面加 const ，修饰的是this指针，让指针指向的值也不可以修改
    // 
    //其实当我们访问 m_age 这个属性 的时候，默认在前面加了 this->m_age ，，表示是当前 对象的属性
    //this 指针的本质 是指针常量  指针的指向是不可以修改的
    // person53 * const this;  
    // 当我们在  成员函数后面加 const  之后，指针指向的值也不可以修改了
    void showperson() const{
        m_B = 100;
        //m_A = 100;
        //this = NULL;    //this 指针不可以修改指针的指向
    }

    //属性 -- 成员属性 --成员变量
    int m_A;
    // 想建一个特殊的成员属性，即使在常函数中，也可以修改这个值
    //需要在前面加一个 关键字 mutable
    mutable int m_B;
};
void test5301() {
    person53 p53;
    p53.showperson();
}

//常对象
//在对象前面加 const，变为常对象

void test5302() {
    const person53 p5302;

    // p5302.m_A = 100;   //报错，因为常函数不可以修改成员属性

    // m_B 是一个特殊的值，在常对象下也可以修改
    p5302.m_B = 100;

    //常函数只能调用常函数
    //p5302.func53();   //报错，因为普通函数是可以修改成员属性的，但是常对象是不可以修改成员属性的，
    
}
int main53() {


    system("pause");
    return 0;
}