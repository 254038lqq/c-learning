#include<iostream>
#include<string>
using namespace std;

//����Ȩ��   --- ����
//����Ȩ��    public         ��Ա  ���ڿ��Է��ʣ�����  ����   ���� 
//����Ȩ��    protected      ��Ա  ���ڿ��Է��ʣ�����  ������ ����           ����  Ҳ����  ���ʸ����еı�������
//˽��Ȩ��    private        ��Ա  ���ڿ��Է��ʣ�����  ������ ����           ����  ������  ���ʸ����е�˽������

class Person {

//����Ȩ��    public 
public:
    string  p_name;    //����

//����Ȩ��    protected   
protected:
    string p_car;      //����
     
//˽��Ȩ��    private    
private:
    int p_password;     //���п�����


//����������Ķ�������
// дһ����������
public:
    void func32(){
        p_name = "����";
        p_car = "������";
        p_password = 123456;
    }
};
int main321() {
    //ʵ����һ���������
    Person person007;
    person007.p_name = "�Ŷ�";
    cout << person007.p_name << endl;
    //person007.p_car = "����";       //����Ȩ�����ݣ���������ʲ���
    //person007.p_password = 456789;   //˽��Ȩ�����ݣ���������ʲ���
    person007.func32();
    cout << person007.p_name << endl;

    system("pause");
    return 0;
}