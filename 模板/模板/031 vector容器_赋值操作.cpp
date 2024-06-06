#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// vector 容器赋值操作
void printVector031(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//赋值操作
void test03101()
{
    vector<int> v1; //无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector031(v1);

    //1.等号赋值
    vector<int>v2;
    v2 = v1;
    printVector031(v2);

    //2.assign 方式赋值   将[beg, end)区间中的数据拷贝赋值给本身。
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());  //前闭后开
    printVector031(v3);

    //3.assign  将n个elem拷贝赋值给本身
    vector<int>v4;
    v4.assign(10, 100);
    printVector031(v4);
}
int main031() {

    test03101();


    system("pause");
    return 0;
}