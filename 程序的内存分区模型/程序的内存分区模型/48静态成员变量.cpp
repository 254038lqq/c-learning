#include<iostream>
#include<string>
using namespace std;
//��̬��Ա����
class person48 {
public:
    //i.���ж�����ͬһ������
    //ii.�ڱ���׶η����ڴ�
    //iii.���������������ʼ��
    static int p_A;

//��̬��Ա����Ҳ���з���Ȩ�޵�
private:
    static int p_B;
};

//�����ʼ��
//int p_A =100������д��һ��ȫ�ֱ�����Ҫ����  person48::   ��ʾΪ  person48  �������µ� һ����̬��Ա
int person48::p_A = 100;
int person48::p_B = 200;
void test4801() {
    person48 p48;
    cout << p48.p_A << endl;

    person48 p482;
    //����̬��Ա�����޸�Ϊ200

    p48.p_A = 200;
    //���ʱ�� ��̬��Ա������ֵ���޸���
    cout << p48.p_A << endl;
}
//��̬��Ա����������ĳ��������Ϊ���еĶ��󶼹���ͬһ������
//��˾�̬��Ա���������ַ��ʷ�ʽ
//1.ͨ��������з���.
//2.ͨ���������з���
void test4802() {
    //1.ͨ��������з���
    person48 p48;
    cout << p48.p_A << endl;
    //2.ͨ���������з���
    cout << person48::p_A << endl;

    //3.��̬��Ա����Ҳ���з���Ȩ�޵�
    //cout << person48::p_B << endl;   //˽��Ȩ�ޣ����ɷ���
}

int main48() {
    //test4801();
    test4802();
    system("pause");
    return 0;
}