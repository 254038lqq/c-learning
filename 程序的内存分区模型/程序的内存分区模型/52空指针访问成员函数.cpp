#include<iostream>
#include<string>
using namespace std;

//��ָ����ʳ�Ա����
// 
//����һ���˵���
class person52 {
//public����������������Ա����--��Ա����--���캯��
public:
    void showclassname() {
        cout << "this is a person52 class" << endl;
    }


    //��ʵ�����Ƿ��� m_age ������� ��ʱ��Ĭ����ǰ����� this->m_age ������ʾ�ǵ�ǰ ���������
    //������   ����һ����ָ��������  ���ԵĻ��ͻᱨ��
    void showpersonage() {
        
        //�����ԭ�������Ϊ�����ָ���� null
        if (this == NULL) {
            return;
        }

        cout << "age = " << m_age <<  endl;

    }
    //����һ����������--��Ա����--��Ա����
    int m_age;
};
void test5201() {
    //����һ��  person52 ���͵�ָ��,ָ���

    person52* p = NULL;


    p->showclassname();
    //����ֵ���ʳ�Ա���������ʳ�Ա���ԣ�����
    p->showpersonage();
}
int main52() {

    test5201();


    system("pause");
    return 0;
}