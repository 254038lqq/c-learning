#include<iostream>
#include<string>
using namespace std;
/*
    ��Ա��������Ϊ˽��
    �ŵ�1�������г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
    �ŵ�2������дȨ�ޣ����ǿ��Լ�����ݵ���Ч��
*/
class Preson34 {

public:
    //��������
    void setName(string name) {
        p_name = name;
    }
    //��ȡ����
     string getName() {
        return p_name;
    }
     //��ȡ����
     int getAge() {
         return p_age;
     }

     //����ż��
     void setIdol(string idol) {
         p_odol = idol;
     }

private:
    string  p_name;   //���� �ɶ���д   
    int p_age =18;       //����  ֻ��
    string p_odol;   //ż��  ֻд
};


int main34() {
    Preson34 p007;
    //��������
    //p007.p_name = "����";  //˽�����Բ��ɷ���

    //��������   �ɶ���д
    //д
    p007.setName("����");
    //��
    cout << " ������ " << p007.getName() << endl;

    //ֻ��
    p007.getAge();
    cout <<"p007.getAge():"<< p007.getAge() << endl;

    //ֻд   ������
    p007.setIdol("����");   

    system("pause");
    return 0;
}