#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test2501()
{
    string str = "hello world";

    //1.通过  [] 方式 取字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // 通过 at 方式访问单个字符
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;
    //字符修改
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;

}
int main25() {

    test2501();


    system("pause");
    return 0;
}