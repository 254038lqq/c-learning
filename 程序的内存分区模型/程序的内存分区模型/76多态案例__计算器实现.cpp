#include<iostream>
#include<string>
using namespace std;

//�ֱ�������ͨд���Ͷ�̬����ʵ�ּ�����
//��ͨʵ�� 
class Calculator76 {
public: 
    int getResult(string oper) { 
        if (oper == "+") { 
            return m_Num1 +m_Num2; 
        }
        else if (oper == "-") { 
            return m_Num1 - m_Num2; 
        }
        else if (oper == "*") { 
            return m_Num1 * m_Num2; 
        }
 //���Ҫ�ṩ�µ����㣬��Ҫ�޸�Դ��
 //����ʵ�����У����ᳫ����ԭ��
// ����ԭ�򣺶���չ���п��������޸Ľ��йر�
    } 
public: 
    int m_Num1; 
    int m_Num2; 
};
 void test7601() { 
     //��ͨʵ�ֲ��� 
     Calculator76 c; 
     c.m_Num1 = 10; 
     c.m_Num2 = 10; 
     cout << c.m_Num1 << " + " <<c.m_Num2 << " = " << c.getResult("+") << endl;
     cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
     cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
 }

 //��̬ʵ�� 
    //����������� 
 //��̬�ŵ㣺
     // ������֯�ṹ������
     // �ɶ���ǿ��
     // ����ǰ�ںͺ��ڵ���չ�Լ�ά��
 class AbstractCalculator76 {
 public:

     virtual int getResult()
     {
         return 0;
     }
     int m_Num1;
     int m_Num2;
 };
 //�ӷ������� 
 class AddCalculator76 :public AbstractCalculator76 { 
 public: 
     int getResult() {
        return m_Num1 + m_Num2; 
    } 
 };
 //���������� 
 class SubCalculator76 :public AbstractCalculator76 {
 public: 
     int getResult() { 
         return m_Num1 - m_Num2; 
     } 
 };
 //�˷������� 
 class MulCalculator76 :public AbstractCalculator76 { 
 public: 
     int getResult() {
         return m_Num1 * m_Num2; 
     } 
 };
 void test7602() { 
     //�����ӷ������� 
     //ʹ����new�ؼ�������̬���ڶѣ�heap���з����ڴ�ռ䣬�Դ洢һ��AddCalculator76���ʵ����������ʵ���ĵ�ַ��ֵ����abcָ�������
     AbstractCalculator76 *abc = new AddCalculator76; 
     abc->m_Num1 = 10;
     abc->m_Num2 = 10; 
     cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
     delete abc; //�����˼ǵ�����

     //��������������
     //���ٵ�ʱ���ǽ����������ݸ��ͷ��ˣ�����ָ�������û�б䣬����һ��AbstractCalculator76 ���͵�ָ��
     abc = new SubCalculator76;
     abc->m_Num1 = 10;
     abc->m_Num2 = 10;
     cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
     delete abc;

     //�����˷�������
     abc = new MulCalculator76;
     abc->m_Num1 = 10;
     abc->m_Num2 = 10;
     cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
     delete abc;
 }
int main76() {

    test7601();
    test7602();

    system("pause");
    return 0;
}