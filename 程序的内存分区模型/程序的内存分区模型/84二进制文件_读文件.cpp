#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�������ļ�   ���ļ�

class Person84 { 
public: 
    char m_Name[64]; 
    int m_Age; 
};
void test8401() {
    //1.����ͷ�ļ�
    //2.����������
    // ifstream ifs��
    //3.���ļ�  �ж��ļ��Ƿ�ɹ���
    //ifs.open("person.txt", ios::in | ios::binary); 
    fstream ifs("person.txt", ios::in | ios::binary); 
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    Person84 p;
    ifs.read((char*)&p, sizeof(p));
    cout << "������ " << p.m_Name << " ���䣺 " << p.m_Age << endl;

    //5.�ر��ļ�
}
int main84() {
    test8401();
    system("pause");
    return 0;
}