#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

void test03601()
{
    vector<int> v;
    //Ԥ���ռ�
    v.reserve(100000);
    //ͳ�ƿ��ٵĴ���
    int num = 0;
    int* p = NULL;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
        if (p != &v[0]) {
            p = &v[0];
            num++;
        }
    }
    cout << "num:" << num << endl;
    cout << " v.capacity() = " << v.capacity() << endl;
}

int main036() {

    test03601();


    system("pause");
    return 0;
}