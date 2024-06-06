#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector 容器 插入和删除
    push_back(ele); //尾部插入元素ele
    pop_back(); //删除最后一个元素
    insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
    insert(const_iterator pos, int count,ele); //迭代器指向位置pos插入count个元素ele
    erase(const_iterator pos); //删除迭代器指向的元素
    erase(const_iterator start, const_iterator end); //删除迭代器从start到end之间的元素
    clear(); //删除容器中所有元素
*/
void printVector033(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//插入和删除
void test03301()
{
    vector<int> v1;
    //尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector033(v1);  //10 20 30 40 50


    //尾删
    v1.pop_back();
    printVector033(v1); //10 20 30 40

    //插入  第一个参数是迭代器
    //迭代器指向位置pos插入元素ele
    v1.insert(v1.begin(), 100); 
    printVector033(v1);      //100  10 20 30 40

    //迭代器指向位置pos插入count个元素ele
    v1.insert(v1.begin(), 2, 1000);
    printVector033(v1);  // 1000 1000 100 10 20 30 40 

    //删除  第一个参数也是迭代器
    //删除迭代器指向的元素
    v1.erase(v1.begin()); 
    printVector033(v1);   //1000 100 10 20 30 40

    //删除迭代器指向的第三个元素
    v1.erase(v1.begin()+ 2); //1000 100 20 30 40 
    printVector033(v1);
    //清空
    //删除迭代器从start到end之间的元素
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector033(v1);
}
int main033() {

    test03301();


    system("pause");
    return 0;
}