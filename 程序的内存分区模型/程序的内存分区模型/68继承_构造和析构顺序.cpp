#include<iostream>
#include<string>
using namespace std;

//�̳��еĹ��������˳��

class Base68 {
public: 
    Base68() {
        cout << "Base���캯��!" << endl; 
    } 
    ~Base68() {
        cout << "Base��������!"<< endl;
    }
};
class Son68 : public Base68 {
public: 
    Son68() {
        cout << "Son���캯��!" << endl; 
    } 
    ~Son68() {
        cout << "Son��������!" << endl; 
    }
};

void test6801() { 
    //Base68 B68;
    //�̳��� �ȵ��ø��๹�캯�����ٵ������๹�캯��������˳���빹���෴ 
    Son68 s68; 
}

int main68() {

    test6801();
    system("pause");
    return 0;
}