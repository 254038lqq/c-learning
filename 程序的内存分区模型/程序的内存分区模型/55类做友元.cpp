#include<iostream>
#include<string>
using namespace std;


//������Ԫ

//�뺯���������ơ����������������ǰ���߱������������
class Building55; 

class goodGay {
public:
    goodGay();
    void visit();  //�ιۺ���  ���� Building �е�����
private: 
    Building55* building;
};

class Building55 { 
    //���߱����� goodGay����Building��ĺ����ѣ����Է��ʵ�Building����˽������ 
    friend class goodGay;
//��Ϊ--��Ա����--��Ա����--���캯��
public: 
    Building55();

//���� -- ��Ա����---��Ա����--
public: 
    string m_SittingRoom; //����
private: 
    string m_BedRoom;//���� 
};

//����ʵ�ֳ�Ա����
//�������� �������� Building  �µĳ�Ա����
Building55::Building55() { 
    this->m_SittingRoom = "����"; 
    this->m_BedRoom = "����"; 
}

goodGay::goodGay() { 
    //����һ��������Ķ���
    building = new Building55; 
}
void goodGay::visit() {
     cout << "�û������ڷ���" << building->m_SittingRoom << endl; 
     cout << "�û������ڷ���" << building->m_BedRoom << endl; 
}
void test5501() {
    //ʵ��������  ������һ�����Ϊ goodGay �Ķ��� gg
    goodGay gg; 
    //����  goodGay��� visit() ����
    gg.visit();
}
int main55() {

    test5501();

    system("pause");
    return 0;
}