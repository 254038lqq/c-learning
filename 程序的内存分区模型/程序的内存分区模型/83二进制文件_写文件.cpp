#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//�������ļ�д�ļ�
class Person83 { 
public: 
    // ʹ��  ����Ϊ char ���ַ�������  ���洢����
    char m_Name[64];       
    int m_Age; 
};
//�������ļ� д�ļ� 
void test8301() { 
    //1������ͷ�ļ�
    // 
    //2���������������
    fstream ofs;

    //3�����ļ�
    ofs.open("person.txt", ios::out | ios::binary);

    //����������+���ļ�
    //ofstream ofs("person.txt", ios::out | ios::binary);
    

    //4��д�ļ�
    Person83 p = { "����" , 20 };
    // ֱ�Ӷ� p ȡ��ַ  ���ص��� һ�� *person  ���͵����ݣ�����ǿת�� (const char*)  sizeof(p) --���ݵĳ���
    ofs.write((const char*)&p, sizeof(p));
    //5���ر��ļ�
    ofs.close();
}
int main() {

    test8301();

    system("pause");
    return 0;
}