#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//���Һ��滻
void test2301()
{
    //����
    //find�����Ǵ�������rfind��������
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
    {
        cout << "δ�ҵ�" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl; /////  3
    } 
    //rfind��������  7
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}
void test2302()
{
    //�滻
    //replace���滻ʱ��Ҫָ�����ĸ�λ���𣬶��ٸ��ַ����滻��ʲô�����ַ���
    //�� �±�Ϊ 1 ��λ���������ַ���bcd�� �滻Ϊ "1111"
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