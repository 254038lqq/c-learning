#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


//swap(vec); // ��vec�뱾���Ԫ�ػ���
void printVector035(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test003501() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector035(v1);


    vector<int> v2;
    for (int i = 100; i < 110; i++) {
        v2.push_back(i);
    }
    printVector035(v2);


    //��������
    cout << "������" << endl;
    v1.swap(v2);
    printVector035(v1);
    printVector035(v2);


}

void test03502()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++) {
        v.push_back(i);
    }
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
    v.resize(3);
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
    //�����ڴ�
    vector<int>(v).swap(v); //�������� ::��ǰִ�н������������
    cout << "v������Ϊ��" << v.capacity() << endl;
    cout << "v�Ĵ�СΪ��" << v.size() << endl;
}
int main035() {

    test003501();
    test03502();


    system("pause");
    return 0;
}