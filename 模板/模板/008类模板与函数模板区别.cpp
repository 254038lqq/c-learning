#include<iostream>
#include<string>
using namespace std;

//��ģ���뺯��ģ�������
//��ģ��
template<class NameType, class AgeType = int>
class Person008
{
public:
    Person008(NameType name, AgeType age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
    }
public:
    NameType m_Name;
    AgeType m_Age;
};
//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test00801()
{
    // Person p("�����", 1000); // ���� ��ģ��ʹ��ʱ�򣬲��������Զ������Ƶ�
    Person008 <string, int>p("�����", 1000); //����ʹ����ʾָ�����͵ķ�ʽ��ʹ����ģ��
    p.showPerson();
}
//2����ģ����  ģ������б���  ������Ĭ�ϲ���
void test00802()
{
    Person008 <string> p("��˽�", 999); //��ģ���е�ģ������б� ����ָ��Ĭ�ϲ���
    p.showPerson();
}

int main008() {
    test00801();
    test00802();



    system("pause");
    return 0;
}