#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;


void MyPrint(int val)
{
    cout << val << endl;
}
//vector ������������������� ָ��
void test01501() {
    // ����һ������  Ҫ��ŵ���������Ϊ int  ������Ϊ v01
    //vector   ���� <vector> ͷ�ļ��� std::vector ����ģ���ࡣ
    //<int> ģ�����
    //���������� vector ʵ��������
    vector<int> v01;

    //����β�巨�������в�������
    v01.push_back(10);
    v01.push_back(20);
    v01.push_back(30);
    v01.push_back(40);

    //ͨ�����������������е�����
    vector<int>::iterator itbegin = v01.begin();          //��ʼ��������ָ�������е�һ��Ԫ��
    vector<int>::iterator itend = v01.end();             //������������ָ�����������һ��Ԫ�ص���һ��λ��
    
    //��һ�ֱ�����ʽ
    cout << "��һ�ֱ�����ʽ" << endl;
    while (itbegin != itend) {
        
        cout << *itbegin << endl;
        itbegin++;
    }

    //�ڶ��ֱ�����ʽ
    cout << "�ڶ��ֱ�����ʽ" << endl;
    for (vector<int>::iterator it = v01.begin(); it != v01.end(); it++) {
        cout << *it << endl;
    }

    //�����ֱ�����ʽ
    //���� STL �ṩ�ı�׼�����㷨��  ͷ�ļ�<algorithm>    MyPrint�ص�����
    cout << "�����ֱ�����ʽ" << endl;
    for_each(v01.begin(), v01.end(), MyPrint);


}

int main015() {

    test01501();


    system("pause");
    return 0;
}