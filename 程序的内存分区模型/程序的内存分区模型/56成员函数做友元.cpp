#include<iostream>
#include<string>
using namespace std;

//��Ա��������Ԫ
// 
////�뺯���������ơ����������������ǰ���߱������������
class Building56; 

class goodGay56 {
public:
    //���캯��
    goodGay56();
    //��Ա����--��Ա����
    void visit(); //ֻ��visit������ΪBuilding�ĺ����ѣ����Է�����Building��˽������
    void visit2();
private: 
    //����һ�� Building56 ���͵�ָ��
    Building56* building;
};
class Building56 { 
    //���߱����� goodGay���е�visit��Ա���� ��Building�����ѣ����Է���˽������ 
    friend void goodGay56::visit();
public: 
    //���캯��
    Building56();
public: 
    string m_SittingRoom; //����
    private: string m_BedRoom;//���� 
};

//����ʵ�ֳ�Ա����
Building56::Building56() { 
    this->m_SittingRoom = "����"; 
    this->m_BedRoom = "����"; 
}
goodGay56::goodGay56() { 
    //ʹ����new�ؼ�������̬���ڶѣ�heap���з����ڴ�ռ䣬�Դ洢һ��Building56���ʵ����������ʵ���ĵ�ַ��ֵ����buildingָ�������
    building = new Building56; 
}
void goodGay56::visit() {
    cout << "�û���visit���ڷ���" << building->m_SittingRoom << endl; 
    cout << "�û���visit���ڷ���" << building->m_BedRoom << endl; 
}
void goodGay56::visit2() {
    cout << "�û���visit2���ڷ���" << building->m_SittingRoom << endl; 
    //cout << "�û������ڷ���" << building->m_BedRoom << endl; 
}
void test5601() {
    goodGay56 gg; 
    gg.visit();
}
int main56() {


    test5601();

    system("pause");
    return 0;
}