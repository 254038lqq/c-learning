#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//�ַ��������ɾ��
void test2601()
{
    string str = "hello";
    //�ӵ�һ��λ�ò��� ��111��
    str.insert(1, "vvv");
    cout << str << endl;
    //��1��λ�ÿ�ʼɾ��  3���ַ�
    str.erase(1, 3); //��1��λ�ÿ�ʼ3���ַ�
    cout << str << endl;
}
int main26() {

    test2601();


    system("pause");
    return 0;
}