#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;


//deque ���캯��

//�� const  ʹ��ֻ������ʣ����������޸�   ���ʱ������� Ҳ��Ҫ�޸�Ϊ  deque<int>::const_iterator
void printdeque0371(const deque<int>& d) {
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
        cout << *it << " ";
        cout << endl;
    }
}
void test03701() {

    //Ĭ�Ϲ��췽ʽ
    deque<int> d1;
    for (int i = 0; i < 10; i++) {
        d1.push_back(i);
    }
    printdeque0371(d1);

    //���䷽ʽ
    deque<int> d2(d1.begin(), d1.end());
    printdeque0371(d2);

    // n ���� �ķ�ʽ
    deque<int>d3(10, 100); 
    
    printdeque0371(d3);


    //��������
    deque<int> d4 = d3;
    printdeque0371(d4);

}
int main037() {

    test03701();
    

    system("pause");
    return 0;
}