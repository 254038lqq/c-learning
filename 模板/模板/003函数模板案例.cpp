#include<iostream>
#include<string>
using namespace std;
/*
����������
    ���ú���ģ���װһ������ĺ��������ԶԲ�ͬ�������������������
    �������Ӵ�С�������㷨Ϊѡ������
    �ֱ�����char�����int������в���
*/

//�����ĺ���ģ��
template<typename T>
void mySwap003(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T> // Ҳ�����滻��typename
//����ѡ�����򣬽��ж�����Ӵ�С������
void mySort003(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //��������±�

        for (int j = i + 1; j < len; j++)
        {
            //�϶������ֵ �� ����������ֵ ҪС��˵�� j �±�������������ֵ
            if (arr[max] < arr[j])
            {
                max = j;  //�������ֵ�±�
            }
        }
        if (max != i) //�����������±겻��i����������
        {
            mySwap003(arr[max], arr[i]);
        }
    }
}//��ӡ�����ģ��
template<typename T>
void printArray003(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test00301()
{
    //����char����
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort003(charArr, num);
    printArray003(charArr, num);
}
void test00302()
{
    //����int����
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 ,12};
    cout << "T1intArr�� " << typeid(intArr).name() << endl;
    int num = sizeof(intArr) / sizeof(int);
    mySort003(intArr, num);
    printArray003(intArr, num);
}
int main003() {

    test00301();
    test00302();


    system("pause");
    return 0;
}