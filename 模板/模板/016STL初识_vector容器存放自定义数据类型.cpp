#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//�Զ�����������
class Person016 {
public:
    Person016(string name, int age) {
        m_Name = name;
        m_Age = age;
    }
public:
    string m_Name;
    int m_Age;
};
//��Ŷ���
void test01601() {
    //����һ�� ��Ϊ v �� vector ���� �������ŵ���������Ϊ Person016
    vector<Person016> v;
    //��������
    Person016 p1("aaa", 10);
    Person016 p2("bbb", 20);
    Person016 p3("ccc", 30);
    Person016 p4("ddd", 40);
    Person016 p5("eee", 50);
    //����β�巨���������������
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //(*it)  ��һ�� <person016>  ���͵���������
    for (vector<Person016>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "test01601 ����Name:" << (*it).m_Name << "test01601 ���� Age:" << (*it).m_Age << endl;
    }
}
//����Զ�����������ָ��  ����ָ��
void test01602() {
    vector<Person016*> v;
    //��������
    Person016 p1("aaa", 10);
    Person016 p2("bbb", 20);
    Person016 p3("ccc", 30);
    Person016 p4("ddd", 40);
    Person016 p5("eee", 50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //��������
    for (vector<Person016*>::iterator it = v.begin(); it != v.end(); it++) {
        // (*it)  ��һ�� <person016 *>  ���͵���������  ��һ��ָ�� 
        Person016* p = (*it);
        cout << "test01602 ����Name:" << p->m_Name << " test01602 ����Age:" << (*it)->m_Age << endl;
    }
}
int main016() {
    test01601();
    test01602();



    system("pause");
    return 0;
}