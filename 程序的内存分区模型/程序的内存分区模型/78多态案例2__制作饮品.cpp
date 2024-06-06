#include<iostream>
#include<string>
using namespace std;
/*
����������
    ������Ʒ�Ĵ�������Ϊ����ˮ - ���� - ���뱭�� - ���븨��
    ���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ
*/
//����������Ʒ 
class AbstractDrinking78 { 
public: 
    //��ˮ 
    virtual void Boil() = 0; 
    //���� 
    virtual void Brew() = 0; 
    //���뱭�� 
    virtual void PourInCup() = 0;
    //���븨�� 
    virtual void PutSomething() = 0; 
    //�涨����
    void MakeDrink() { 
        Boil(); 
        Brew(); 
        PourInCup(); 
        PutSomething(); 
    } 
};
//�������� 
class Coffee78 : public AbstractDrinking78 { 
public: 
    //��ˮ 
    virtual void Boil() { 
        cout << "��ũ��ɽȪ!"<< endl; 
    } 
    //���� 
    virtual void Brew() { 
        cout << "���ݿ���!" << endl; 
    } 
    //���뱭�� 
    virtual void PourInCup(){ 
        cout << "�����ȵ��뱭��!" << endl;
    } 
    //���븨�� 
    virtual void PutSomething() { 
        cout << "����ţ��!" << endl;
    }   
};
//������ˮ 
class Tea78 : public AbstractDrinking78 { 
public: 
    //��ˮ
    virtual void Boil() { 
        cout << "������ˮ!" <<endl; 
    } 
    //���� 
    virtual void Brew() { 
        cout << "���ݲ�Ҷ!" << endl; 
    } 
    //���뱭�� 
    virtual void PourInCup() { 
        cout<< "����ˮ���뱭��!" << endl;
    }
    //���븨�� 
    virtual void PutSomething() { 
        cout << "�������!" << endl; 
    } 
};
//ҵ���� 
void DoWork(AbstractDrinking78* drink) { 
    drink->MakeDrink(); 
    delete drink; 
}
void test7801() { 
    DoWork(new Coffee78); 
    cout << "--------------" << endl; 
    DoWork(new Tea78); }
int main78() {
    test7801();

    system("pause");
    return 0;
}