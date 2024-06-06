#include<iostream>
#include<string>
using namespace std;

//分别利用普通写法和多态技术实现计算器
//普通实现 
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
 //如果要提供新的运算，需要修改源码
 //在真实开发中，。提倡开闭原则
// 开闭原则：对扩展进行开发，对修改进行关闭
    } 
public: 
    int m_Num1; 
    int m_Num2; 
};
 void test7601() { 
     //普通实现测试 
     Calculator76 c; 
     c.m_Num1 = 10; 
     c.m_Num2 = 10; 
     cout << c.m_Num1 << " + " <<c.m_Num2 << " = " << c.getResult("+") << endl;
     cout << c.m_Num1 << " - " << c.m_Num2 << " = " << c.getResult("-") << endl;
     cout << c.m_Num1 << " * " << c.m_Num2 << " = " << c.getResult("*") << endl;
 }

 //多态实现 
    //抽象计算器类 
 //多态优点：
     // 代码组织结构清晰，
     // 可读性强，
     // 利于前期和后期的扩展以及维护
 class AbstractCalculator76 {
 public:

     virtual int getResult()
     {
         return 0;
     }
     int m_Num1;
     int m_Num2;
 };
 //加法计算器 
 class AddCalculator76 :public AbstractCalculator76 { 
 public: 
     int getResult() {
        return m_Num1 + m_Num2; 
    } 
 };
 //减法计算器 
 class SubCalculator76 :public AbstractCalculator76 {
 public: 
     int getResult() { 
         return m_Num1 - m_Num2; 
     } 
 };
 //乘法计算器 
 class MulCalculator76 :public AbstractCalculator76 { 
 public: 
     int getResult() {
         return m_Num1 * m_Num2; 
     } 
 };
 void test7602() { 
     //创建加法计算器 
     //使用了new关键字来动态地在堆（heap）中分配内存空间，以存储一个AddCalculator76类的实例，并将该实例的地址赋值给了abc指针变量。
     AbstractCalculator76 *abc = new AddCalculator76; 
     abc->m_Num1 = 10;
     abc->m_Num2 = 10; 
     cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
     delete abc; //用完了记得销毁

     //创建减法计算器
     //销毁的时候是将堆区的数据给释放了，但是指针的类型没有变，还是一个AbstractCalculator76 类型的指针
     abc = new SubCalculator76;
     abc->m_Num1 = 10;
     abc->m_Num2 = 10;
     cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
     delete abc;

     //创建乘法计算器
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