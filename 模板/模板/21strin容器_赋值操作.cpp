#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
/*
��ֵ�ĺ���ԭ�ͣ�
    string& operator=(const char* s); //char*�����ַ��� ��ֵ����ǰ���ַ���
    string& operator=(const string &s); //���ַ���s  ������ǰ���ַ���
    string& operator=(char c); //�ѵ����ַ�  ��ֵ����ǰ���ַ���
    string& assign(const char *s); //���ַ���s������ǰ���ַ���
    string& assign(const char *s, int n); //���ַ���s��  ǰn���ַ�  ������ǰ���ַ���
    string& assign(const string &s); //��  �ַ���s  ������ǰ�ַ���
    string& assign(int n, char c); //��n���ַ�c������ǰ�ַ���
*/
void test2101() {
    string str1;
    str1 = "hellow word";
    cout << "str1 = " << str1 << endl;

    string str2;
    str2 = str1;
    cout << "str2 = " << str2 << endl;

    string str3;
    str3 = "L";
    cout << "str3 = " << str3 << endl;

    string str4;
    str4.assign("hellow C++");
    cout << "str4 = " << str4 << endl;

    string str5;
    str5.assign("hellow C++",4);
    cout << "str5= " << str5 << endl;

    string str6;
    str6.assign(str5);
    cout << "str6= " << str6 << endl;

    string str7;
    str7.assign(5,'v');
    cout << "str7= " << str7 << endl;

}
int main21() {

    test2101();


    system("pause");
    return 0;
}