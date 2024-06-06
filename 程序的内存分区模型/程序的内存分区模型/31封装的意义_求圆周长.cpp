#include<iostream>
#include<string>
using namespace std;

//设计一个圆类，求圆周长
//圆求周长的公式：2 * PI * 半径


float PI = 3.14;
//class 类名{ 访问权限：属性 / 行为 }；
//class 代表设计一个类，类后面紧跟着的就是类名称
class Circle {
    //访问权限
    // 公共权限
public:

    //属性
    // 半径
    int C_r;

    //行为
    //求圆的周长
    double calculateYZC() {
        return 2 * PI * C_r;

    }
};
int main31() {  


    //通过圆类  创建具体的圆（对象）
    //实例化（通过一个类  创建一个对象的过程）
    Circle circle007;

    //给圆对象的属性进行赋值
    circle007.C_r = 10;

    cout << "圆周长为：" << circle007.calculateYZC() << endl;




    system("pause");
    return 0;
}