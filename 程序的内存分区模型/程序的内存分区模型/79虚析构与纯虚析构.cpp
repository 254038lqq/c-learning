#include<iostream>
#include<string>
using namespace std;
//�������봿������

class Animal79 {
public:
    Animal79()
    {
        cout << "Animal ���캯�����ã�" << endl;
    }
    //���麯��
    virtual void Speak() = 0;
    //������������virtual�ؼ��֣��������������
    //virtual ~Animal79()
    // {
    //     cout << "Animal�������������ã�" << endl;
    //}
    //��������   ��Ҫ����  Ҳ��Ҫ��ʵ��
    // ���˴�������֮�������Ҳ���ڳ����࣬�޷�ʵ����
    virtual ~Animal79() = 0;
};
Animal79::~Animal79() { 
    cout << "Animal ���������������ã�" << endl; 
}
//�Ͱ�����ͨ���麯������һ���������˴���������������Ҳ��һ�������ࡣ���ܹ���ʵ������
class Cat79 : public Animal79 {
public: 
    Cat79(string name) {
        cout << "Cat���캯�����ã�" << endl; 
        //���ݴ�����������new string  ���ص���һ�� string ���͵�ָ�룬ʹ�ô�����  string����ָ��     string* m_Name;  ȥά��
        m_Name = new string(name);
    }   
    virtual void Speak() { 
        cout << *m_Name << "Сè��˵��!" << endl; 
    } 
    //��cat�����������У�Ӧ�ý��ڶ�������������   string name  ���ͷŸɾ�
    ~Cat79() {
        
        if (this->m_Name != NULL) { 
            cout << "Cat������������!" << endl;
            delete m_Name; 
            m_Name = NULL; 
        }
    }
public: 
    //��һ������è���Ե�ָ��
    string* m_Name;
};
void test7901() {
    //����ָ��ָ���������
    Animal79* animal = new Cat79("Tom"); 
    animal->Speak();
    //����ָ����������ʱ�򣬲������������������������������������ж������ԣ������ڴ�й©
    //ͨ������ָ��ȥ�ͷţ��ᵼ�����������������ɾ�������ڴ�й©
    //��ô���������������һ������������
    //���������������������ͨ������ָ���ͷ��������
    delete animal;
}
int main79() {

    test7901();


    system("pause");
    return 0;
}