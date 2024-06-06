#include<iostream>
#include<string>
using namespace std;

/*===============联系案例1：设计立方体类==============
* 求出立方体的面积和体积
* 分别用全局函数和成员函数判断两个立方体是否相等
*/
class cube {
    //1.属性
    //长
    //宽
    //高
    //2.行为
    //获取立方体体积
    //获取立方体的高

public:

    //设置长
    void setl(int l) {
        c_l = l;
    }
    //获取长
    int getl() {
        return c_l;
    }
    //设置宽
    void setw(int w) {
        c_w = w;
    }
    //获取宽
    int getw() {
        return c_w;
    }
    //设置高
    void seth(int h) {
        c_h = h;
    }
    //获取高
    int geth() {
        return c_h;
    }
    //获取立方体面积
    int calculatearea() {
        return 2 * c_l * c_w + 2 * c_l * c_h + 2 * c_h * c_w;
    }
    //获取立方体体积
    int calculateVolume() {
        return c_l * c_w * c_h;
    }

    //利用成员函数来判断两个立方体是否相等
    bool issamebyclass(cube& c) {
        if (c_l == c.getl() && c.geth() == c_w && c_h == c.getw()) {
            return true;
        }

        return false;

    };
    

//成员属性设置为私有====将所有成员属性设置为私有，可以自己控制读写权限
private:
    int c_l;    //长
    int c_w;    //宽
    int c_h;    //高
};

//利用全局函数来判断两个立方体是否相等
bool issame(cube &c1, cube &c2 ) {
    if (c1.getl() == c2.getl() && c1.geth() == c2.geth() && c1.getw() == c2.getw()) {
        return true;
    }
    
     return false;
    
};
int main35() {
    //实例化一个立方体
    cube cube007;
    cube007.setl(10);
    cube007.setw(10);
    cube007.seth(10);
    cout << "立方体cube007的体积为：" << cube007.calculateVolume() << endl;
    cout << "立方体cube007的面积为：" << cube007.calculatearea() << endl;

    //第二个立方体
    cube cube008;
    cube008.setl(10);
    cube008.setw(10);
    cube008.seth(12);

    //利用全局函数来判断两个立方体是否相等
    bool ret = issame(cube007, cube008);
    if (ret) {
        cout << "两个立方体相等" << endl;
    }
    else {
        cout << "两个立方体不相等" << endl;
    }


    //利用成员函数来判断两个立方体是否相等
    bool ret2 = cube007.issamebyclass(cube008);
    if (ret2) {
        cout << "利用成员函数判断两个立方体相等" << endl;
    }
    else {
        cout << "利用成员函数判断两个立方体不相等" << endl;
    }

    system("pause");
    return 0;
}