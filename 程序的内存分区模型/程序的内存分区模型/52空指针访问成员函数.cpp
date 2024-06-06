#include<iostream>
#include<string>
using namespace std;

//空指针访问成员函数
// 
//定义一个人的类
class person52 {
//public作用域下有两个成员函数--成员方法--构造函数
public:
    void showclassname() {
        cout << "this is a person52 class" << endl;
    }


    //其实当我们访问 m_age 这个属性 的时候，默认在前面加了 this->m_age ，，表示是当前 对象的属性
    //当我们   定义一个空指针来访问  属性的话就会报错。
    void showpersonage() {
        
        //报错的原因就是因为传入的指针是 null
        if (this == NULL) {
            return;
        }

        cout << "age = " << m_age <<  endl;

    }
    //定义一个年龄属性--成员变量--成员属性
    int m_age;
};
void test5201() {
    //定义一个  person52 类型的指针,指向空

    person52* p = NULL;


    p->showclassname();
    //控制值访问成员函数，访问成员属性，报错
    p->showpersonage();
}
int main52() {

    test5201();


    system("pause");
    return 0;
}