#include<iostream>
#include<string>
using namespace std;
/*
    浅拷贝：简单的赋值拷贝操作
        m_height = p.height;
    深拷贝：在堆区重新申请空间，进行拷贝操作
        m_height = new int(*p.height);
    //如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
    总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题
*/
class person45 {
public:
    //无参构造
    person45() {
        cout << "person45无参构造函数调用" << endl;
    }
    //有参构造
    person45(int age,int height) {
        p_age = age;
        p_height = new int(height);
        cout << "person45有参构造函数调用" << endl;
    }
    //拷贝构造
    person45(const person45 &p) {
        p_age = p.p_age;
        p_height = new int(*p.p_height);
        cout << "person45拷贝构造函数调用" << endl;
    }
    int p_age;
    int* p_height;
    //析构函数
    ~person45() {
        cout << "析构函数!" << endl;
        if (p_height != NULL)
        {
            delete p_height;
        }
    }

};
void test4501() {
    person45 p1(18, 180);
    person45 p2(p1);
    cout << "p1的年龄： " << p1.p_age << " 身高： " << *p1.p_height << endl;
    cout << "p2的年龄： " << p2.p_age << " 身高： " << *p2.p_height << endl;
}
int main45() {

    test4501();


    system("pause");
    return 0;
}