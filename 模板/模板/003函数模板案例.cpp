#include<iostream>
#include<string>
using namespace std;
/*
案例描述：
    利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
    排序规则从大到小，排序算法为选择排序
    分别利用char数组和int数组进行测试
*/

//交换的函数模板
template<typename T>
void mySwap003(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<class T> // 也可以替换成typename
//利用选择排序，进行对数组从大到小的排序
void mySort003(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i; //最大数的下标

        for (int j = i + 1; j < len; j++)
        {
            //认定的最大值 比 遍历出的数值 要小，说明 j 下标才是真正的最大值
            if (arr[max] < arr[j])
            {
                max = j;  //更新最大值下标
            }
        }
        if (max != i) //如果最大数的下标不是i，交换两者
        {
            mySwap003(arr[max], arr[i]);
        }
    }
}//打印数组的模板
template<typename T>
void printArray003(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void test00301()
{
    //测试char数组
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    mySort003(charArr, num);
    printArray003(charArr, num);
}
void test00302()
{
    //测试int数组
    int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 ,12};
    cout << "T1intArr： " << typeid(intArr).name() << endl;
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