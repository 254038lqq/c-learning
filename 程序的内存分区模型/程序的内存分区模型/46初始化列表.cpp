#include<iostream>
#include<string>
using namespace std;

/*
    作用： C++提供了初始化列表语法，用来初始化属性
    语法：构造函数()：属性1(值1),属性2（值2）... {}
*/
class Person46 {
public:
    //1.传统方式初始化
    /*
    Person46(int a, int b, int c) {
        p_a = a;
        p_b = b;
        p_c = c;

    }
    */
    //初始化列表初始化属性
    Person46(int a, int b, int c) :p_a(a), p_b(b), p_c(c) {

    }

    int p_a;
    int p_b;
    int p_c;

};
void test4601() {
    //传统方式初始化
    //Person46 p46(10,20,30);

    Person46 p46(20,30,10);
    cout << " p_a = "<< p46.p_a << endl;
    cout << " p_b = " << p46.p_b << endl;
    cout << " p_c = " << p46.p_c << endl;
}
int main46() {
    test4601();




    system("pause");
    return 0;
}