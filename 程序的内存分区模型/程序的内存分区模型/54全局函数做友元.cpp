#include<iostream>
#include<string>
using namespace std;


//ȫ�ֺ�������Ԫ

class Building54 {

    //���߱����� goodGayȫ�ֺ��� �� Building��ĺ����ѣ����Է������е�˽������  
    friend void goodGay(Building54* building);

public:
    Building54()
    {
        this->m_SittingRoom = "����";
        this->m_BedRoom = "����";
    }
    string m_SittingRoom;   //����

private :
    string m_BedRoom;      // ����
};
//ȫ�ֺ���
//ȫ�ֺ�������Ԫ��Ҫ��  ��  ���ʼ����һ��  ���йؼ��� friend �ĺ�������
void goodGay(Building54* building) {
    cout << "�û������ڷ��ʹ������Կ����� " << building->m_SittingRoom << endl; 

    //˽�����Բ��ɷ���
    //��Ҫʹ���ѷ���˽������ 
    cout << "�û������ڷ���˽���������ң�" << building->m_BedRoom << endl;
}
void test5401() { 
    Building54 b;
    goodGay(&b); 
}
int main54() {


    test5401();

    system("pause");
    return 0;
}