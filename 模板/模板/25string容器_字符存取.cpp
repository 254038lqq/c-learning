#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test2501()
{
    string str = "hello world";

    //1.ͨ��  [] ��ʽ ȡ�ַ�
    for (int i = 0; i < str.size(); i++)
    {
        cout << str[i] << " ";
    }
    cout << endl;

    // ͨ�� at ��ʽ���ʵ����ַ�
    for (int i = 0; i < str.size(); i++)
    {
        cout << str.at(i) << " ";
    }
    cout << endl;
    //�ַ��޸�
    str[0] = 'x';
    str.at(1) = 'x';
    cout << str << endl;

}
int main25() {

    test2501();


    system("pause");
    return 0;
}