#include<iostream>
#include<string>
using namespace std;

//栈区数据注意事项，-------不要返回局部变量的地址
//栈区的数据由编译器管理开辟和释放

int* func() { 

    //局部变量，存放在栈区，栈区的数据在函数执行完成后自动释放
    int a = 10; 
    //返回局部变量的地址
    return &a; 
}
int main02() {
    int* p = func();

    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;
    cout << *p << endl;    
    cout << *p << endl;
    cout << *p << endl;


    system("pause");
    return 0;
}