#include<iostream>
#include<string>
using namespace std;


//�������ͺ���
void swapInt001(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

//���������ͺ���
void swapDouble001(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}
//1.ֱ��д��������������������Ҫʵ�������������͵Ľ�����Ҫд�ཻܶ������
void test00101()
{
    int a = 10;
    int b = 20;
    swapInt001(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    double c = 1.1;
    double d = 2.2;
    swapDouble001(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

//2.����ģ��
// template<typename T>
    //template-- - ��������ģ��
    //typename -- - ���������ķ�����һ���������ͣ�������class����
    //T-- - ͨ�õ��������ͣ����ƿ����滻��ͨ��Ϊ��д��ĸ
template<typename T>
void myswap001(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
//����ģ��ʵ����������
void test00102()
{
    int a = 10;
    int b = 20;
    //�����ַ�ʽʹ�ú���ģ��
    //1���Զ������Ƶ�
    myswap001(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    //2����ʾָ������
    myswap001<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

}
 
int main001() {

    //test00101();
    test00102();

    system("pause");
    return 0;
}