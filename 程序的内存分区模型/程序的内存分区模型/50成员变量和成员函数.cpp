#include<iostream>
#include<string>
using namespace std;

//��Ա���� �� ���� �Ƿֿ��洢��
class person5001 {

};
void test5001() {
    person5001 person50;
    //�ն���ռ���ڴ�ռ�Ϊ��1
    //c++���������ÿ���ն���Ҳ����һ���ֽڿռ䣬��Ϊ�����ֿն���ռ�ڴ��λ��
    //ÿ���ն���ҲӦ����һ����һ�޶����ڴ��ַ
    cout << "size of p = " << sizeof(person50) << endl;
}
class person5002 {
    int person5002_a;    // �Ǿ�̬��Ա����                             ������Ķ����ϵ�����
    static int person5002_b;    // ��̬��Ա����  ��������  �����ʼ��   ��������Ķ�����
    int func5002(){}    // �Ǿ�̬��Ա����                               ��������Ķ�����
    static int func5003() {}    // ��̬��Ա����                               ��������Ķ�����
};
int person5002_b = 20;
void test5002() {
    person5002 person5002;
    cout << "size of p = " << sizeof(person5002) << endl;
}
int main50() {

    //test5001();
    test5002();


    system("pause");
    return 0;
}