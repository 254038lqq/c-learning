#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//字符串插入和删除
void test2601()
{
    string str = "hello";
    //从第一个位置插入 ”111“
    str.insert(1, "vvv");
    cout << str << endl;
    //从1号位置开始删除  3个字符
    str.erase(1, 3); //从1号位置开始3个字符
    cout << str << endl;
}
int main26() {

    test2601();


    system("pause");
    return 0;
}