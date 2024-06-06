#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;

void printDeque038(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//赋值操作
void test03801()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque038(d1);

    //1.等号赋值
    //deque& operator=(const deque &deq); //重载等号操作符
    deque<int>d2;
    d2 = d1;
    printDeque038(d2);

    //2.assing(begin,end)   /将[beg, end)区间中的数据拷贝赋值给本身。
    deque<int>d3;
    d3.assign(d1.begin(), d1.end());
    printDeque038(d3);

    //3.assign(n, elem); //将n个elem拷贝赋值给本身。
    deque<int>d4;
    d4.assign(10, 100);
    printDeque038(d4);
}
int main038() {

    test03801();


    system("pause");
    return 0;
}