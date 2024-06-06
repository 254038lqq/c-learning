#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#include <deque>

void printDeque039(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//大小操作
void test03901()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque039(d1);

    //判断容器是否为空
    if (d1.empty()) {
        cout << "d1为空!" << endl;
    }
    else {
        cout << "d1不为空!" << endl;
        //统计大小
        cout << "d1的大小为：" << d1.size() << endl;
    }
    //重新指定大小
    d1.resize(15, 1);
    printDeque039(d1);

    d1.resize(5);
    printDeque039(d1);
}
int main039() {
    test03901();


    system("pause");
    return 0;
}