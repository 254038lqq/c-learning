#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//swap(vec); // 将vec与本身的元素互换
void printVector035(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test003501() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector035(v1);


    vector<int> v2;
    for (int i = 100; i < 110; i++) {
        v2.push_back(i);
    }
    printVector035(v2);


    //互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector035(v1);
    printVector035(v2);


}

void test03502()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    v.resize(3);
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
    //收缩内存
    vector<int>(v).swap(v); //匿名对象 ::当前执行结束，立马回收
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}
int main035() {

    test003501();
    test03502();


    system("pause");
    return 0;
}