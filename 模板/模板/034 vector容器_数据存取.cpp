#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


/*
    at(int idx); //��������idx��ָ������
    operator[]; //��������idx��ָ������
    front(); //���������е�һ������Ԫ��
    back(); //�������������һ������Ԫ��
*/

void test03401()
{
    vector<int>v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    // ����  [] ��ʽ���� �����е�Ԫ��
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    // ���� ��Ա���� at ������
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1.at(i) << " ";
    }
    cout << endl;
    cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
    cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;
}
int main034() {
    test03401();

    system("pause");
    return 0;
}