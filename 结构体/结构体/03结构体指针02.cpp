#include<iostream>
#include<string>
#include<algorithm> // ������׼���е�������
using namespace std;

// ����ṹ��
struct Student {
    string name;
    int age;
    int score;
};

// �Զ���ȽϺ�������������
bool compareByAge(const Student& a, const Student& b) {
    return a.age < b.age; // ����������������
}

int main() {
    // �����ṹ������
    Student s[2] = { {"����", 19, 100}, {"����", 12, 90} };

    // ͨ��ָ��ָ��ṹ��������׵�ַ
    Student* p = s;

    // ͨ��ָ����ʽṹ������е�����
    cout << "����ǰ�Ľṹ�����飺" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "������" << p[i].name << "  ���䣺" << p[i].age << "  ������" << p[i].score << endl;
    }

    // �Խṹ�����鰴�������������
    sort(s, s + 2, compareByAge);

    // ��ӡ�����Ľ��
    cout << "\n�����������Ľṹ�����飺" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "������" << s[i].name << "  ���䣺" << s[i].age << "  ������" << s[i].score << endl;
    }
    system("pause");
    return 0;
}
