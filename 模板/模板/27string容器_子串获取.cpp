#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//子串
void test2701()
{
    string str = "abcdefg";
    //返回由 1 开始的 3 个字符组成的字符串
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;  //bcd


    string email = "hello@sina.com";
    int pos = email.find("@");  
    cout << "pos: " << pos << endl;    //5
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}
int main27() {

    test2701();


    system("pause");
    return 0;
}