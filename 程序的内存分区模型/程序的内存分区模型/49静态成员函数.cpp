#include<iostream>
#include<string>
using namespace std;
//��̬��Ա����
//i.���ж�����ͬһ������
//ii.��̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
class person49 {
public:
    //��̬��Ա����
    static void func49() {
        //��̬��Ա�������Է��ʾ�̬��Ա����
        p49_A = 10;
        //p49_B = 200;  //��̬��Ա����  �����Է���  �Ǿ�̬��Ա���������޷����ֵ������Ǹ������
        cout << "static void func49()����" << endl;

    }
    //��̬��Ա����
    //�������������ⶨ��
    static int p49_A;
    //�Ǿ�̬��Ա����
    int p49_B;

    //��̬��Ա����Ҳ���з���Ȩ�޵�
private:
    static void func492() {
        cout << "static void func492()����" << endl;

    }

};
//���ⶨ��
int person49::p49_A = 100;

void test4901() {
    //��̬��Ա���������ַ��ʷ�ʽ
    //ͨ��������з���
    person49 p49;
    p49.func49();
    //ͨ���������з���
    person49::func49();

    //person49::func492();   //������ʲ���˽�о�̬��Ա����
}


int main49() {
    test4901();

    system("pause");
    return 0;
}