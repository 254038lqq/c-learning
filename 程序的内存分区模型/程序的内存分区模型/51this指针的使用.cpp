#include<iostream>
#include<string>
using namespace std;


//1.解决名称冲突

//2.返回对象本身用 *this

class Person5101 {
public:
    //构造函数
    Person5101(int age)
    {
        //age = age;
        // 这样写的话 会有名称冲突，无法将传入的参数传给成员属性 age
        // 方法1  将成员属性与传入的参数做一个区分，成员属性定义为  int m_age;  而不是int age;
        // 方法2 使用  this->age = age;
        // 
        // this指针指向被调用的成员函数所属的对象    谁调用这个构造函数   this指针就指向那个对象
        //1、当形参和成员变量同名时，可用this指针来区分
        this->age = age;
    }

    //如果要返回对象本身的话，需要用引用的方式进行返回
    // 如果 不写引用，是以值的方式返回的，返回的是  Person5101 
    //一次调用之后，返回的不是本体，是按照本体返回的新的数据 （以值的方式返回的话，会调用拷贝构造函数，复制一份新的数据出来，形成新的对象）
    Person5101& PersonAddPerson(Person5101 &p)
    {
        //将 p 的年龄加到 自身
        this->age += p.age;

        //返回对象本身
        //这样的话返回的还是对象本身，就可以追加调用
        // 当  PersonAddPerson 构造函数被调用的时候，this 是指向调用这个构造函数的对象 的指针，我们对他进行解引用 *this 指向的就是 这个对象的本体
        //      eg: 当p2 去调用 PersonAddPerson的时候，this就是指向 p2 的指针，我们使用  *this 对其进行 解引用 的话，得到的就是 p2 的本体
        return *this; 
    }
    int age;
};
void test5101() {
    Person5101 p5101(18);
    cout << "p5101的年龄为： " << p5101.age << endl;
}
void test5102() {
    Person5101 p1(10); 
    cout << "p1.age = " << p1.age << endl;
    Person5101 p2(10);

    //p2.PersonAddPerson(p1);
    //cout << "p2.age = " << p2.age << endl;

    //链式编程思想
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}
int main51() {

    //test5101();
    test5102();


    system("pause");
    return 0;
}