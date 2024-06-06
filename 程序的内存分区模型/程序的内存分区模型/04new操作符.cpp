#include<iostream>
#include<string>
using namespace std;

//1. new 的基本用法
int* func4() { 
    //在堆区创建整形数据
    //返回的是 该数据类型的指针
    int* a = new int(10); 
    return a; 
}

void test01() {
    int* p = func4();
    cout << *p << endl;
    cout << *p << endl;
    //堆区的数据由程序员管理开辟，程序员管理释放
    //利用delete释放堆区数据
    delete p;
    //内存已经被释放，再次访问就是非法操作
    //cout << *p << endl; //报错，释放的空间不可访问

}
//2.在堆区利用new开辟数组
void test02() {
    //创建10个整型数据的数组，在堆区
    int* arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        //给10个元素赋值 100~109
        arr[i] = i + 100;
    }
    for (int i = 0; i < 10; i++)
    {
        //打印
        cout << arr[i] << endl;
    }
    //释放数组 delete 后加 []
    delete[] arr;

}
int main04() {

    ///test01();
    test02();


    system("pause");
    return 0;
}