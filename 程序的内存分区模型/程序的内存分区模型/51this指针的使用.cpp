#include<iostream>
#include<string>
using namespace std;


//1.������Ƴ�ͻ

//2.���ض������� *this

class Person5101 {
public:
    //���캯��
    Person5101(int age)
    {
        //age = age;
        // ����д�Ļ� �������Ƴ�ͻ���޷�������Ĳ���������Ա���� age
        // ����1  ����Ա�����봫��Ĳ�����һ�����֣���Ա���Զ���Ϊ  int m_age;  ������int age;
        // ����2 ʹ��  this->age = age;
        // 
        // thisָ��ָ�򱻵��õĳ�Ա���������Ķ���    ˭����������캯��   thisָ���ָ���Ǹ�����
        //1�����βκͳ�Ա����ͬ��ʱ������thisָ��������
        this->age = age;
    }

    //���Ҫ���ض�����Ļ�����Ҫ�����õķ�ʽ���з���
    // ��� ��д���ã�����ֵ�ķ�ʽ���صģ����ص���  Person5101 
    //һ�ε���֮�󣬷��صĲ��Ǳ��壬�ǰ��ձ��巵�ص��µ����� ����ֵ�ķ�ʽ���صĻ�������ÿ������캯��������һ���µ����ݳ������γ��µĶ���
    Person5101& PersonAddPerson(Person5101 &p)
    {
        //�� p ������ӵ� ����
        this->age += p.age;

        //���ض�����
        //�����Ļ����صĻ��Ƕ������Ϳ���׷�ӵ���
        // ��  PersonAddPerson ���캯�������õ�ʱ��this ��ָ�����������캯���Ķ��� ��ָ�룬���Ƕ������н����� *this ָ��ľ��� �������ı���
        //      eg: ��p2 ȥ���� PersonAddPerson��ʱ��this����ָ�� p2 ��ָ�룬����ʹ��  *this ������� ������ �Ļ����õ��ľ��� p2 �ı���
        return *this; 
    }
    int age;
};
void test5101() {
    Person5101 p5101(18);
    cout << "p5101������Ϊ�� " << p5101.age << endl;
}
void test5102() {
    Person5101 p1(10); 
    cout << "p1.age = " << p1.age << endl;
    Person5101 p2(10);

    //p2.PersonAddPerson(p1);
    //cout << "p2.age = " << p2.age << endl;

    //��ʽ���˼��
    p2.PersonAddPerson(p1).PersonAddPerson(p1).PersonAddPerson(p1);
    cout << "p2.age = " << p2.age << endl;
}
int main51() {

    //test5101();
    test5102();


    system("pause");
    return 0;
}