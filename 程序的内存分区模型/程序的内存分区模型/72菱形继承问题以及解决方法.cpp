#include<iostream>
#include<string>
using namespace std;

//���μ̳������Ѿ��������
 class Animal72 { 
 public: 
     int m_Age; 
 };
//�̳�ǰ��virtual�ؼ��ֺ󣬱�Ϊ��̳� 
//��ʱ�����ĸ���Animal��Ϊ����� 
class Sheep72 : virtual public Animal72{
};
class Tuo72 : virtual public Animal72 {
}; 
class SheepTuo72 : public Sheep72, public Tuo72 {
};

void test7201() {
    SheepTuo72 st72; 
    st72.Sheep72::m_Age = 100; 
    st72.Tuo72::m_Age = 200;
    //�����μ̳У���������ӵ����ͬ���ݣ���Ҫ���������������
    cout << "st.Sheep::m_Age = " << st72.Sheep72::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st72.Tuo72::m_Age << endl;
    // �����������֪����һ�ݾͿ����ˣ����μ̳е������������ݣ���Դ�˷�
    // ������̳� ������μ̳е�����

    cout << "st.m_Age = " << st72.m_Age << endl;
}
int main72() {
    test7201();
    system("pause");
    return 0;
}