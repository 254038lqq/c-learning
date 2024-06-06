#include<iostream>
#include<string>
using namespace std;


int* func2() { 
    //利用 new 关键字  可以将数据开辟到堆区
    //返回的是新开辟空间的地址编号
    //用指针接受返回的地址
    //指针本质上也是局部变量，放在栈上，指针保存的数据放在堆区
    int* a = new int(10); 
    return a; 
}
int main03() {

    //在堆区开辟数据
    //用指针接受地址的返回值
    int* p = func2();

    cout << *p << endl;



    system("pause");
    return 0;
}