#include<iostream>
#include<string>
using namespace std;
/*
    ��ģ���г�Ա��������ͨ���г�Ա��������ʱ����������ģ�
        ��ͨ���еĳ�Ա����һ��ʼ�Ϳ��Դ���
        ��ģ���еĳ�Ա�����ڵ���ʱ�Ŵ���
*/
class Person0091
{
public:
    void showPerson0091()
    {
        cout << "Person0091 show" << endl;
    }
};
class Person0092
{
public:
    void showPerson0092()
    {
        cout << "Person0092 show" << endl;
    }
};
template<class T>
class MyClass009
{
public:
    //�����Ա�����ڴ���ʱ����ȷ���������� ����Ϊͨ������
    T obj;
    //��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������
    void fun0091() { 
        obj.showPerson0091();
    }
    void fun0092() {
        obj.showPerson0092(); 
    }
};
void test00901()
{
    // ��������  Person0091  ��ʵ����������д����ʱ��m.fun0092() ������ʾ��������ʱ�Żᱨ��˵���������òŻ�ȥ������Ա����
    MyClass009<Person0091> m;

    m.fun0091();
    // m.fun0092();//��������˵���������òŻ�ȥ������Ա����
}
int main009() {

    test00901();

    system("pause");
    return 0;
}