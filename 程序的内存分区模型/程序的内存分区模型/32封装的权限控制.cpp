#include<iostream>
#include<string>
using namespace std;

//访问权限   --- 三种
//公共权限    public         成员  类内可以访问，类外  可以   访问 
//保护权限    protected      成员  类内可以访问，类外  不可以 访问           儿子  也可以  访问父亲中的保护内容
//私有权限    private        成员  类内可以访问，类外  不可以 访问           儿子  不可以  访问父亲中的私有内容

class Person {

//公共权限    public 
public:
    string  p_name;    //姓名

//保护权限    protected   
protected:
    string p_car;      //汽车
     
//私有权限    private    
private:
    int p_password;     //银行卡密码


//大括号里面的都叫类内
// 写一个公共函数
public:
    void func32(){
        p_name = "张三";
        p_car = "拖拉机";
        p_password = 123456;
    }
};
int main321() {
    //实例化一个具体对象
    Person person007;
    person007.p_name = "张儿";
    cout << person007.p_name << endl;
    //person007.p_car = "奔驰";       //保护权限内容，在类外访问不到
    //person007.p_password = 456789;   //私有权限内容，在类外访问不到
    person007.func32();
    cout << person007.p_name << endl;

    system("pause");
    return 0;
}