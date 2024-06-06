#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector ������ �����ʹ�С
    empty();         //�ж������Ƿ�Ϊ��
    capacity();      //����������
    size();          //����������Ԫ�صĸ���
    resize(int num); //����ָ�������ĳ���Ϊnum���������䳤������Ĭ��ֵ�����λ�á�
                     //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ����
    resize(int num, elem); //����ָ�������ĳ���Ϊnum���������䳤������elemֵ�����λ�á�
                         //���������̣���ĩβ�����������ȵ�Ԫ�ر�ɾ��
                     */

void printVector032(vector<int>& v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void test03201() {
    vector<int> v1;
    for (int i = 0; i < 10; i++) {
        v1.push_back(i);
    }
    printVector032(v1);
    if (v1.empty()) {
        cout << "v1Ϊ��" << endl;
    }
    else {
        cout << "v1��Ϊ��" << endl;
        cout << "v1������ = " << v1.capacity() << endl;
        cout << "v1�Ĵ�С = " << v1.size() << endl;
    }

    //resize ����ָ����С��������ָ���������ռ����Ĭ����0�����λ��
    v1.resize(15);
    printVector032(v1);
    //resize ����ָ����С��������ָ���������ռ��С����ĩβ�����������ȵ�Ԫ�ر�ɾ����
    v1.resize(5);
    printVector032(v1);

    //resize ����ָ����С��������ָ���������ռ������elemֵ�����λ�á�
    v1.resize(15,100);
    printVector032(v1);
    //resize ����ָ����С��������ָ���������ռ��С����ĩβ�����������ȵ�Ԫ�ر�ɾ����
    v1.resize(5,100);
    printVector032(v1);
    
}
int main032() {
    test03201();

    system("pause");
    return 0;
}