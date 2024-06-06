#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void MyPrint(int val)
{
    cout << val << endl;
}
//vector 容器存放内置数据类型 指针
void test01501() {
    // 声明一个容器  要存放的数据类型为 int  ，名称为 v01
    //vector   来自 <vector> 头文件的 std::vector 容器模板类。
    //<int> 模板参数
    //赋予声明的 vector 实例的名称
    vector<int> v01;

    //利用尾插法向容器中插入数据
    v01.push_back(10);
    v01.push_back(20);
    v01.push_back(30);
    v01.push_back(40);

    //通过迭代器访问容器中的数据
    vector<int>::iterator itbegin = v01.begin();          //起始迭代器，指向容器中第一个元素
    vector<int>::iterator itend = v01.end();             //结束迭代器，指向容器中最后一个元素的下一个位置
    
    //第一种遍历方式
    cout << "第一种遍历方式" << endl;
    while (itbegin != itend) {
        
        cout << *itbegin << endl;
        itbegin++;
    }

    //第二种遍历方式
    cout << "第二种遍历方式" << endl;
    for (vector<int>::iterator it = v01.begin(); it != v01.end(); it++) {
        cout << *it << endl;
    }

    //第三种遍历方式
    //利用 STL 提供的标准遍历算法，  头文件<algorithm>    MyPrint回调函数
    cout << "第三种遍历方式" << endl;
    for_each(v01.begin(), v01.end(), MyPrint);


}

int main015() {

    test01501();


    system("pause");
    return 0;
}