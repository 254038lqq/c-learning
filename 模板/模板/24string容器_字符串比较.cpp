#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//�ַ����Ƚ�
void test2401()
{
    string s1 = "hello";
    string s2 = "aello";
    int ret = s1.compare(s2);
    if (ret == 0) {
        cout << "s1 ���� s2" << endl;
    }
    else if (ret > 0)
    {
        cout << "s1 ���� s2" << endl;
    }
    else
    {
        cout << "s1 С�� s2" << endl;
    }
}

int main24() {

    test2401();

    system("pause");
    return 0;
}