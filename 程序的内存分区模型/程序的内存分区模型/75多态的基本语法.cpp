#include<iostream>
#include<string>
using namespace std;

//��̬
class Animal75 {
public: 
    //Speak���������麯�� 
    //����ǰ�����virtual�ؼ��֣�����麯������ô�������ڱ����ʱ��Ͳ���ȷ�����������ˡ�
    virtual void speak75() {
        cout << "������˵��" << endl; 
    }
};
class Cat75 :public Animal75 { 
public: 
    void speak75() { 
        cout << "Сè��˵��" << endl; 
    } 
};
class Dog75 :public Animal75 {
public:
    void speak75()
    {
        cout << "С����˵��" << endl;
    }
}; 
//����ϣ������ʲô������ô�͵���ʲô����ĺ��� 
// //���������ַ�ڱ���׶ξ���ȷ������ô��̬���� 
// //���������ַ�����н׶β���ȷ�������Ƕ�̬����
// Animal75 & animal = cat
//ִ��˵���ĺ�����ʱ��
// ��ַ���  �ڱ���׶�ȷ��������ַ    ����Cat75 cat; DoSpeak75(cat);  ����ִ��ʱ������Ƕ�����˵��������Сè��˵��
//�����ִ����è˵������ô������ַ�Ͳ�����ǰ�󶨣���Ҫ�����н׶ν��а󶨣���ַ���
void DoSpeak75(Animal75& animal) { 
    animal.speak75(); 
} 
//��̬��̬���������� 
// //1���м̳й�ϵ 
// //2��������д�����е��麯�� 
//��̬ʹ�ã� 
// //����ָ�������ָ���������
void test7501() {
    Cat75 cat; 
    DoSpeak75(cat);
    Dog75 dog;
    DoSpeak75(dog);
}
void tets7502() {
    //32λ��X86��ָ����4���ֽ�   64λָ����8���ֽ�
    cout << "sizeof animal = " << sizeof(Animal75) << endl;
}
int main75() {
   // test7501();
    tets7502();
    system("pause");
    return 0;
}