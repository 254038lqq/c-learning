#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//查找和替换
void test2301()
{
    //查找
    //find查找是从左往后，rfind从右往左
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl; /////  3
    } 
    //rfind从右往左  7
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}
void test2302()
{
    //替换
    //replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串
    //从 下标为 1 的位置起，三个字符（bcd） 替换为 "1111"
    string str1 = "abcdefgde";
    str1.replace(1, 3, "1111");
    cout << "str1 = " << str1 << endl;
}
int main23() {

    test2301();
    test2302();


    system("pause");
    return 0;
}