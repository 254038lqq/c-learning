#include<iostream>
#include<string>
using namespace std;
//ģ��ľ�����
//ģ���ͨ���Բ��������ܵ�
//��Щ�ض��������ͣ���Ҫ�þ��廯��ʽ������ʵ��

//��ͨ����ģ��
//�Ա����������Ƿ���ȵ�ģ��
template<class T>
bool mycompare006(T &a, T &b)
{
    if (a = b) {
        return true;
    } 
    else {
        return false;
    }
}
void test00601() {
    int a = 10;
    int b = 10;
    bool ret = mycompare006(a, b);
    if (ret) {
        cout << "a==b" << endl;
    }
    else {
        cout << "a!=b" << endl;
    }
}



class Person006
{
public:
    Person006(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};

//���廯����ʾ���廯��ԭ�ͺ�ʵ����template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool mycompare006(Person006& p1, Person006& p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test00602()
{
    Person006 p1("Tom", 10);
    Person006 p2("Tom", 10);
    //�Զ����������ͣ����������ͨ�ĺ���ģ��
    //���Դ������廯��Person�������͵�ģ�壬�������⴦���������
    bool ret = mycompare006(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }
}
int main006() {

    //test00601();
    test00602();

    system("pause");
    return 0;
}