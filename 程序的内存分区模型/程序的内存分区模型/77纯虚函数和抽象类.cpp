#include<iostream>
#include<string>
using namespace std;

//���麯���ͳ�����
class Base77 {
public: 
    //���麯�� 
    //����ֻҪ��һ�����麯���ͳ�Ϊ������ 
    // ��������ص㣺
        //1. �������޷�ʵ�������� 
        // 2.���������д�����еĴ��麯��������Ҳ���ڳ����� 
    virtual void func77() = 0;
};
class Son77 :public Base77 { 
public: 
    //���������д�����еĴ��麯���������޷�ʵ��������
    virtual void func77() { 
        cout << "func ��������" << endl;
    };
};
void test7701() {
    // Base77 b77;       //���󣬳������޷�ʵ��������
    // new Base77;      //���󣬳������޷�ʵ��������

    // new����ʲô�������͵��õ�ʲô�����func77������
    //��̬��Ŀ�ľ��������ǵĺ����ӿڸ�ͨ�û���ͨ��һ������ָ�룬����ָ��Ķ���ͬ�����Ե��ò�ͬ�ĺ���
    Base77* base = NULL; 
    base = new Son77;
    base->func77(); 
    delete base;   //�ǵ����� 
}
int main77() {

    test7701();


    system("pause");
    return 0;
}