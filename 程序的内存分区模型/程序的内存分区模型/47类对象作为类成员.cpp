#include<iostream>
#include<string>
using namespace std;

//B�����ж���A��Ϊ��Ա��AΪ�����Ա
//��ô������B����ʱ��A��B�Ĺ����������˳����˭��˭��

//�ֻ���
class Phone47 {  
public:
    Phone47(string pname) {
        cout <<   "Phone47 ���캯������" <<  endl;
        phone_name = pname;
    }
    ~Phone47() {
        cout << "Phone47 ������������" << endl;
    }

    //�ֻ�Ʒ��
    string phone_name;
};

//�� ��
class person47 {
public:
    person47(string name,string pname):p_name(name), p_phone(pname){
        cout << "person47 ���캯������" << endl;
    }
    ~person47() {
        cout << "person47 ������������" << endl;
    }
    //����
    string p_name;
    //�ֻ�
    Phone47 p_phone;
};
//����������Ϊ�����Ա������ʱ�ȹ���������ٹ�������
//������˳���빹��˳���෴
void test47()
{
    person47 p47("����", "ƻ��15max");
    cout << p47.p_name << "����" << p47.p_phone.phone_name << endl;
}
int main47() {

    test47();


    system("pause");
    return 0;
}