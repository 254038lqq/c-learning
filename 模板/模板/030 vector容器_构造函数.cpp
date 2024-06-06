#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
* vector �����Ĺ��캯��
    vector<T> v;                 //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
    vector(v.begin(), v.end());  //��   v[begin(), end())  �����е�Ԫ�ؿ���������   ǰ�պ�
    vector(n, elem);             //���캯����n��elem����������
    vector(const vector &vec);   //�������캯����
*/
//����һ��vector ���� ���� vector �����е�ֵ�����
void printVector030(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test03001()
{
    //1.Ĭ�Ϲ��� / �޲ι���
    vector<int> v1; 
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector030(v1);

    //2. ͨ������ķ�ʽ���й���
    vector<int> v2(v1.begin(), v1.end());
    printVector030(v2);

    //3.ͨ�� n �� elem �ķ�ʽ���й���
    vector<int> v3(10, 100);
    printVector030(v3);

    //4.�������� 
    vector<int> v4(v3);
    printVector030(v4);
}
int main030() {

    test03001();

    system("pause");
    return 0;
}