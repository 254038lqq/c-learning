#include<iostream>
#include<string>
using namespace std;

//���һ��Բ�࣬��Բ�ܳ�
//Բ���ܳ��Ĺ�ʽ��2 * PI * �뾶


float PI = 3.14;
//class ����{ ����Ȩ�ޣ����� / ��Ϊ }��
//class �������һ���࣬���������ŵľ���������
class Circle {
    //����Ȩ��
    // ����Ȩ��
public:

    //����
    // �뾶
    int C_r;

    //��Ϊ
    //��Բ���ܳ�
    double calculateYZC() {
        return 2 * PI * C_r;

    }
};
int main31() {  


    //ͨ��Բ��  ���������Բ������
    //ʵ������ͨ��һ����  ����һ������Ĺ��̣�
    Circle circle007;

    //��Բ��������Խ��и�ֵ
    circle007.C_r = 10;

    cout << "Բ�ܳ�Ϊ��" << circle007.calculateYZC() << endl;




    system("pause");
    return 0;
}