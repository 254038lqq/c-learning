#include<iostream>
#include<string>
using namespace std;

//�ṹ������
//1.����ṹ��
struct Student {
    //��Ա�б�
    //����
    string name;
    //����
    int age;
    //����
    int score;
};

int main20() {
    //2. �����ṹ������
    struct Student stuarr[3] = {
        {"����",19,100},
        {"����", 17, 98},
        {"����", 13, 196},
    };


    //3. �� �ṹ�������е�Ԫ�ظ�ֵ ��
    stuarr[2].name = "����";
    stuarr[2].age = 18;
    stuarr[2].score = 98;

    //4.�����ṹ������
    for (int i = 0; i < 3; i++) {
        cout << "  ������ " << stuarr[i].name
             << "  ���䣺 " << stuarr[i].age
             << "  ������ " << stuarr[i].score << endl;
    }
    system("pause");
    return 0;
}