#include<iostream>
#include<string>
using namespace std;

/*===============��ϵ����1�������������==============
* ������������������
* �ֱ���ȫ�ֺ����ͳ�Ա�����ж������������Ƿ����
*/
class cube {
    //1.����
    //��
    //��
    //��
    //2.��Ϊ
    //��ȡ���������
    //��ȡ������ĸ�

public:

    //���ó�
    void setl(int l) {
        c_l = l;
    }
    //��ȡ��
    int getl() {
        return c_l;
    }
    //���ÿ�
    void setw(int w) {
        c_w = w;
    }
    //��ȡ��
    int getw() {
        return c_w;
    }
    //���ø�
    void seth(int h) {
        c_h = h;
    }
    //��ȡ��
    int geth() {
        return c_h;
    }
    //��ȡ���������
    int calculatearea() {
        return 2 * c_l * c_w + 2 * c_l * c_h + 2 * c_h * c_w;
    }
    //��ȡ���������
    int calculateVolume() {
        return c_l * c_w * c_h;
    }

    //���ó�Ա�������ж������������Ƿ����
    bool issamebyclass(cube& c) {
        if (c_l == c.getl() && c.geth() == c_w && c_h == c.getw()) {
            return true;
        }

        return false;

    };
    

//��Ա��������Ϊ˽��====�����г�Ա��������Ϊ˽�У������Լ����ƶ�дȨ��
private:
    int c_l;    //��
    int c_w;    //��
    int c_h;    //��
};

//����ȫ�ֺ������ж������������Ƿ����
bool issame(cube &c1, cube &c2 ) {
    if (c1.getl() == c2.getl() && c1.geth() == c2.geth() && c1.getw() == c2.getw()) {
        return true;
    }
    
     return false;
    
};
int main35() {
    //ʵ����һ��������
    cube cube007;
    cube007.setl(10);
    cube007.setw(10);
    cube007.seth(10);
    cout << "������cube007�����Ϊ��" << cube007.calculateVolume() << endl;
    cout << "������cube007�����Ϊ��" << cube007.calculatearea() << endl;

    //�ڶ���������
    cube cube008;
    cube008.setl(10);
    cube008.setw(10);
    cube008.seth(12);

    //����ȫ�ֺ������ж������������Ƿ����
    bool ret = issame(cube007, cube008);
    if (ret) {
        cout << "�������������" << endl;
    }
    else {
        cout << "���������岻���" << endl;
    }


    //���ó�Ա�������ж������������Ƿ����
    bool ret2 = cube007.issamebyclass(cube008);
    if (ret2) {
        cout << "���ó�Ա�����ж��������������" << endl;
    }
    else {
        cout << "���ó�Ա�����ж����������岻���" << endl;
    }

    system("pause");
    return 0;
}