#include<iostream>
#include<string>
using namespace std;
/*
    ǳ�������򵥵ĸ�ֵ��������
        m_height = p.height;
    ������ڶ�����������ռ䣬���п�������
        m_height = new int(*p.height);
    //�������������ڶ����������ڴ棬�ᵼ��ǳ�����������ظ��ͷŶ�������
    �ܽ᣺����������ڶ������ٵģ�һ��Ҫ�Լ��ṩ�������캯������ֹǳ��������������
*/
class person45 {
public:
    //�޲ι���
    person45() {
        cout << "person45�޲ι��캯������" << endl;
    }
    //�вι���
    person45(int age,int height) {
        p_age = age;
        p_height = new int(height);
        cout << "person45�вι��캯������" << endl;
    }
    //��������
    person45(const person45 &p) {
        p_age = p.p_age;
        p_height = new int(*p.p_height);
        cout << "person45�������캯������" << endl;
    }
    int p_age;
    int* p_height;
    //��������
    ~person45() {
        cout << "��������!" << endl;
        if (p_height != NULL)
        {
            delete p_height;
        }
    }

};
void test4501() {
    person45 p1(18, 180);
    person45 p2(p1);
    cout << "p1�����䣺 " << p1.p_age << " ��ߣ� " << *p1.p_height << endl;
    cout << "p2�����䣺 " << p2.p_age << " ��ߣ� " << *p2.p_height << endl;
}
int main45() {

    test4501();


    system("pause");
    return 0;
}