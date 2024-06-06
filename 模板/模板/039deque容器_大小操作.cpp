#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#include <deque>

void printDeque039(const deque<int>& d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//��С����
void test03901()
{
    deque<int> d1;
    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }
    printDeque039(d1);

    //�ж������Ƿ�Ϊ��
    if (d1.empty()) {
        cout << "d1Ϊ��!" << endl;
    }
    else {
        cout << "d1��Ϊ��!" << endl;
        //ͳ�ƴ�С
        cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
    }
    //����ָ����С
    d1.resize(15, 1);
    printDeque039(d1);

    d1.resize(5);
    printDeque039(d1);
}
int main039() {
    test03901();


    system("pause");
    return 0;
}