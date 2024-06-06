#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
* vector 容器的构造函数
    vector<T> v;                 //采用模板实现类实现，默认构造函数
    vector(v.begin(), v.end());  //将   v[begin(), end())  区间中的元素拷贝给本身。   前闭后开
    vector(n, elem);             //构造函数将n个elem拷贝给本身。
    vector(const vector &vec);   //拷贝构造函数。
*/
//传入一个vector 容器 ，将 vector 容器中的值打出来
void printVector030(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test03001()
{
    //1.默认构造 / 无参构造
    vector<int> v1; 
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector030(v1);

    //2. 通过区间的方式进行构造
    vector<int> v2(v1.begin(), v1.end());
    printVector030(v2);

    //3.通过 n 个 elem 的方式进行构造
    vector<int> v3(10, 100);
    printVector030(v3);

    //4.拷贝构造 
    vector<int> v4(v3);
    printVector030(v4);
}
int main030() {

    test03001();

    system("pause");
    return 0;
}