#include<iostream>
#include<string>
using namespace std;
/*
    ����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
        ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
        �����ָ�����������޷�����������ڴ�
        ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/
template<class T>
class Base011
{
    T m;
};
//class Son:public Base //����c++������Ҫ����������ڴ棬����֪��������T�����Ͳſ������¼̳�
class Son011 :public Base011<int> //����ָ��һ������
{
};
void test01101()
{
    Son011 c;
}


// ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
// ��ģ��̳���ģ�� ,������T2ָ�������е�T����
template<class T1, class T2>
class Son0112 :public Base011<T2>
{
public:
    Son0112()
    {
        cout << typeid(T1).name() << endl;
        cout << typeid(T2).name() << endl;
    }
    T1 obj;

};
void test01102()
{
    Son0112<int, char> child1;
}
int main011() {


    test01102();

    system("pause");
    return 0;
}