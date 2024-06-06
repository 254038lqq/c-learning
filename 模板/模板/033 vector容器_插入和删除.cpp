#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
vector ���� �����ɾ��
    push_back(ele); //β������Ԫ��ele
    pop_back(); //ɾ�����һ��Ԫ��
    insert(const_iterator pos, ele); //������ָ��λ��pos����Ԫ��ele
    insert(const_iterator pos, int count,ele); //������ָ��λ��pos����count��Ԫ��ele
    erase(const_iterator pos); //ɾ��������ָ���Ԫ��
    erase(const_iterator start, const_iterator end); //ɾ����������start��end֮���Ԫ��
    clear(); //ɾ������������Ԫ��
*/
void printVector033(vector<int> &v) {
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
//�����ɾ��
void test03301()
{
    vector<int> v1;
    //β��
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector033(v1);  //10 20 30 40 50


    //βɾ
    v1.pop_back();
    printVector033(v1); //10 20 30 40

    //����  ��һ�������ǵ�����
    //������ָ��λ��pos����Ԫ��ele
    v1.insert(v1.begin(), 100); 
    printVector033(v1);      //100  10 20 30 40

    //������ָ��λ��pos����count��Ԫ��ele
    v1.insert(v1.begin(), 2, 1000);
    printVector033(v1);  // 1000 1000 100 10 20 30 40 

    //ɾ��  ��һ������Ҳ�ǵ�����
    //ɾ��������ָ���Ԫ��
    v1.erase(v1.begin()); 
    printVector033(v1);   //1000 100 10 20 30 40

    //ɾ��������ָ��ĵ�����Ԫ��
    v1.erase(v1.begin()+ 2); //1000 100 20 30 40 
    printVector033(v1);
    //���
    //ɾ����������start��end֮���Ԫ��
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector033(v1);
}
int main033() {

    test03301();


    system("pause");
    return 0;
}