#include<iostream>
using namespace std;
//����������
int max(int a, int b);
int main() {
    int a = 10;
    int b = 20;
    cout << " max = " << max(a, b) << endl;
}
//�����Ķ���
int max(int a, int b) {
    return a > b ? a : b;
}