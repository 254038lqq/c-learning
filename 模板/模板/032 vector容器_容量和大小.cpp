#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector 容器的 容量和大小
    empty();         //判断容器是否为空
    capacity();      //容器的容量
    size();          //返回容器中元素的个数
    resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
                     //如果容器变短，则末尾超出容器长度的元素被删除。
    resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
                         //如果容器变短，则末尾超出容器长度的元素被删除
                     */

void printVector032(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test03201() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector032(v1);
    if (v1.empty()) {
        cout << "v1为空" << endl;
    }
    else {
        cout << "v1不为空" << endl;
        cout << "v1的容量 = " << v1.capacity() << endl;
        cout << "v1的大小 = " << v1.size() << endl;
    }

    //resize 重新指定大小，若重新指定的容器空间更大，默认用0填充新位置
    v1.resize(15);
    printVector032(v1);
    //resize 重新指定大小，若重新指定的容器空间更小，则末尾超出容器长度的元素被删除。
    v1.resize(5);
    printVector032(v1);

    //resize 重新指定大小，若重新指定的容器空间更大，以elem值填充新位置。
    v1.resize(15,100);
    printVector032(v1);
    //resize 重新指定大小，若重新指定的容器空间更小，则末尾超出容器长度的元素被删除。
    v1.resize(5,100);
    printVector032(v1);
    
}
int main032() {
    test03201();

    system("pause");
    return 0;
}