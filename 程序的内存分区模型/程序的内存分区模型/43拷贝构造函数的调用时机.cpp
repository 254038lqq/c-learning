#include<iostream>
#include<string>
using namespace std;

/*
    C++�п������캯������ʱ��ͨ�����������
        1.ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
        2.ֵ���ݵķ�ʽ������������ֵ
        3.��ֵ��ʽ���ؾֲ�����
*/
class person43{
public:
    //1.���캯��  ���г�ʼ������

    person43() {
        cout << "person43Ĭ�Ϲ��캯���ĵ���" << endl;
    }

    person43(int age) {
        p_age = age;
        cout << "person43�вι��캯���ĵ���" << endl;
    }

    person43(const person43 &p) {
        p_age = p.p_age;
        cout << "person43�������캯���ĵ���" << endl;
    }
    //2.��������  �����������

    ~person43() {
        cout << "person43���������ĵ���" << endl;
    }
    int p_age;

};
//1. ʹ��һ���Ѿ�������ϵĶ�������ʼ��һ���¶���
void test4301() {
    person43 p1(20); //p�����Ѿ��������
    person43 p2(p1); //���ÿ������캯��
    cout << "p2������"<< p2.p_age <<endl;
    //person43 newman2 = man; //��������
    //Person newman3;
    //newman3 = man; //���ǵ��ÿ������캯������ֵ����
}

//2. ֵ���ݵķ�ʽ������������ֵ //�൱��Person p1 = p; 
void doWork(person43 p1) {
}
void test4302() {
   person43 p; //�޲ι��캯�� 
   doWork(p); 
}

//3. ��ֵ��ʽ���ؾֲ����� 
person43 doWork2() {
    person43 p3;
    cout << (int *)&p3 << endl; 
    return p3; 
}
void test4303() { 
    person43 p = doWork2(); 
    cout << (int*)&p << endl; 
}
int main43() {

    //test4301();
    //test4302();
    test4303();


    system("pause");
    return 0;
}