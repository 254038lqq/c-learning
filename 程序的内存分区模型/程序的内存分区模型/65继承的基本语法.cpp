#include<iostream>
#include<string>
using namespace std;

//�̳еĻ����﷨

//��ͨʵ��ҳ��
//Javaҳ�� 
class Java6501 {
public: 
    void header() { 
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl; 
    } 
    void footer() { 
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl; 
    } 
    void left() { 
        cout<< "Java,Python,C++...(���������б�)" << endl; 
    } 
    void content() { 
        cout << "JAVAѧ����Ƶ" << endl; 
    } 
};
//Pythonҳ�� 
class Python6501 { 
public: 
    void header() { 
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl; 
    } 
    void footer() { 
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl; 
    }
    void left() { 
        cout<< "Java,Python,C++...(���������б�)" << endl; 
    } 
    void content() {
        cout << "Pythonѧ����Ƶ" << endl; 
    }
};
//C++ҳ�� 
class CPP6501 { 
public: 
    void header() { 
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" <<endl; 
        } 
    void footer() { 
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl; 
    } 
    void left() {
        cout << "Java,Python,C++...(���������б�)" << endl;
    } 
    void content() { 
        cout << "C++ѧ����Ƶ" << endl; 
    } 
};
void test6501() {
    //Javaҳ�� 
    cout << "Java������Ƶҳ�����£� " << endl;
    Java6501 ja6501;
    ja6501.header();
    ja6501.footer();
    ja6501.left();
    ja6501.content();
    cout << "--------------------" << endl;

    //Pythonҳ��
    cout << "Python������Ƶҳ�����£� " << endl;
    Python6501 py6501;
    py6501.header();
    py6501.footer();
    py6501.left();
    py6501.content();
    cout << "--------------------" << endl;

    //C++ҳ��
    cout << "C++������Ƶҳ�����£� " << endl;
    CPP6501 cp6501;
    cp6501.header();
    cp6501.footer();
    cp6501.left();
    cp6501.content();

}

//�̳�ʵ��ҳ��
//����ҳ�� 
class BasePage65 {
public:
    void header() {
        cout << "��ҳ�������Ρ���¼��ע��...������ͷ����" << endl;
    }
    void footer()
    {
        cout << "�������ġ�����������վ�ڵ�ͼ...(�����ײ�)" << endl;
    }
    void left()
    {
        cout << "Java,Python,C++...(���������б�)" << endl;
    }
};
//Javaҳ�� 
class Java6502 : public BasePage65 { 
public: 
    void content() { 
        cout << "JAVAѧ����Ƶ" << endl; 
    } 
};
//Pythonҳ�� 
class Python6502 : public BasePage65 { 
public: 
    void content() 
    { 
        cout << "Pythonѧ����Ƶ" << endl;
    }
}; 
//C++ҳ�� 
class CPP6502 : public BasePage65 {
public: 
    void content() {
        cout << "C++ѧ����Ƶ" << endl;
    } 
};
void test6502() {
    //Javaҳ�� 
    cout << "Java������Ƶҳ�����£� " << endl;
    Java6502 ja6502;
    ja6502.header();
    ja6502.footer();
    ja6502.left();
    ja6502.content();
    cout << "--------------------" << endl;

    //Pythonҳ��
    cout << "Python������Ƶҳ�����£� " << endl;
    Python6502 py6502;
    py6502.header();
    py6502.footer();
    py6502.left();
    py6502.content();
    cout << "--------------------" << endl;
    //C++ҳ��
    cout << "C++������Ƶҳ�����£� " << endl;
    CPP6502 cp6502;
    cp6502.header();
    cp6502.footer();
    cp6502.left();
    cp6502.content();
}
int main65() {

    //test6501();
    test6502();


    system("pause");
    return 0;
}