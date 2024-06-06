#include<iostream>
#include<string>
using namespace std;

/*
    C++中拷贝构造函数调用时机通常有三种情况
        1.使用一个已经创建完毕的对象来初始化一个新对象
        2.值传递的方式给函数参数传值
        3.以值方式返回局部对象
*/
class person43{
public:
    //1.构造函数  进行初始化操作

    person43() {
        cout << "person43默认构造函数的调用" << endl;
    }

    person43(int age) {
        p_age = age;
        cout << "person43有参构造函数的调用" << endl;
    }

    person43(const person43 &p) {
        p_age = p.p_age;
        cout << "person43拷贝构造函数的调用" << endl;
    }
    //2.析构函数  进行清理操作

    ~person43() {
        cout << "person43析构函数的调用" << endl;
    }
    int p_age;

};
//1. 使用一个已经创建完毕的对象来初始化一个新对象
void test4301() {
    person43 p1(20); //p对象已经创建完毕
    person43 p2(p1); //调用拷贝构造函数
    cout << "p2的年龄"<< p2.p_age <<endl;
    //person43 newman2 = man; //拷贝构造
    //Person newman3;
    //newman3 = man; //不是调用拷贝构造函数，赋值操作
}

//2. 值传递的方式给函数参数传值 //相当于Person p1 = p; 
void doWork(person43 p1) {
}
void test4302() {
   person43 p; //无参构造函数 
   doWork(p); 
}

//3. 以值方式返回局部对象 
person43 doWork2() {
    person43 p3;
    cout << (int *)&p3 << endl; 
    return p3; 
}
void test4303() { 
    person43 p = doWork2(); 
    cout << (int*)&p << endl; 
}
int main43() {

    //test4301();
    //test4302();
    test4303();


    system("pause");
    return 0;
}