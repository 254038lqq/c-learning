#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//�Ӵ�
void test2701()
{
    string str = "abcdefg";
    //������ 1 ��ʼ�� 3 ���ַ���ɵ��ַ���
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