#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;


//deque 构造函数

//加 const  使得只允许访问，而不允许修改   这个时候迭代器 也需要修改为  deque<int>::const_iterator
void printdeque0371(const deque<int>& d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
        cout << endl;
    }
}
void test03701() {

    //默认构造方式
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printdeque0371(d1);

    //区间方式
    deque<int> d2(d1.begin(), d1.end());
    printdeque0371(d2);

    // n 个几 的方式
    deque<int>d3(10, 100); 
    
    printdeque0371(d3);


    //拷贝构造
    deque<int> d4 = d3;
    printdeque0371(d4);

}
int main037() {

    test03701();
    

    system("pause");
    return 0;
}