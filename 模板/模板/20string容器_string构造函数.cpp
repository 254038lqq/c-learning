#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
    string ���캯��ԭ�ͣ�
        string(); //����һ���յ��ַ��� ����: string str;
        string(const char* s); //ʹ���ַ���s��ʼ��
        string(const string& str); //��������   ʹ��һ��string�����ʼ����һ��string����
        string(int n, char c); //ʹ��n���ַ�c��ʼ��
*/

void test2001()
{
    string s1; //�������ַ����������޲ι��캯��
    cout << "str1 = " << s1 << endl;

    const char* str = "hello world";
    string s2(str); //��c_stringת������string
    cout << "str2 = " << s2 << endl;

    string s3(s2); //���ÿ������캯��
    cout << "str3 = " << s3 << endl;

    string s4(10, 'a');
    cout << "str4 = " << s4 << endl;
}
int main20() {


    test2001();

    system("pause");
    return 0;
}