#include<iostream>
#include<string>
using namespace std;

//���һ��ѧ���࣬������������ѧ�ţ����Ը�������ѧ�Ÿ�ֵ��������ʾѧ����������ѧ��
/*
    ���е����Ժ���Ϊ  ����ͳ��Ϊ��Ա
    ����   ��Ա����  ��Ա����
    ��Ϊ   ��Ա����  ��Ա����
*/

//class ����{ ����Ȩ�ޣ����� / ��Ϊ }��
//class �������һ���࣬���������ŵľ���������
class Student {
    //����Ȩ��
    // ����Ȩ��
public:

    //����
    //����
    string s_name;
    //
    int s_id;
   
    //��Ϊ
    //��ʾ������ѧ��
    void showname_id(){
        cout << "����: " << s_name << "    ѧ��: " << s_id << endl;
    };

    //ͨ����Ϊ�����Ը�ֵ
    void setName(string name) {
        s_name = name;
    };
    void setID(int id)
    {
        s_id = id;

    };

};
int main311() {


    //ͨ��ѧ����  ���������ѧ��������
    //ʵ������ͨ��һ����  ����һ������Ĺ��̣�
    Student Student007;

    //��ѧ����������Խ��и�ֵ
    Student007.s_name = "����";
    Student007.s_id = 20240411;
    Student007.showname_id();
    Student007.setName("����");
    Student007.setID(20240412);
    Student007.showname_id();



    




    system("pause");
    return 0;
}