#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// vector ������ֵ����
void printVector031(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//��ֵ����
void test03101()
{
    vector<int> v1; //�޲ι���
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector031(v1);

    //1.�ȺŸ�ֵ
    vector<int>v2;
    v2 = v1;
    printVector031(v2);

    //2.assign ��ʽ��ֵ   ��[beg, end)�����е����ݿ�����ֵ������
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());  //ǰ�պ�
    printVector031(v3);

    //3.assign  ��n��elem������ֵ������
    vector<int>v4;
    v4.assign(10, 100);
    printVector031(v4);
}
int main031() {

    test03101();


    system("pause");
    return 0;
}