#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//自定义数据类型
class Person016 {
public:
    Person016(string name, int age) {
        m_Name = name;
        m_Age = age;
    }
public:
    string m_Name;
    int m_Age;
};
//存放对象
void test01601() {
    //创建一个 名为 v 的 vector 容器 ，里面存放的数据类型为 Person016
    vector<Person016> v;
    //创建数据
    Person016 p1("aaa", 10);
    Person016 p2("bbb", 20);
    Person016 p3("ccc", 30);
    Person016 p4("ddd", 40);
    Person016 p5("eee", 50);
    //利用尾插法向容器中添加数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    //(*it)  是一个 <person016>  类型的数据类型
    for (vector<Person016>::iterator it = v.begin(); it != v.end(); it++) {
        cout << "test01601 ：：Name:" << (*it).m_Name << "test01601 ：： Age:" << (*it).m_Age << endl;
    }
}
//存放自定义数据类型指针  对象指针
void test01602() {
    vector<Person016*> v;
    //创建数据
    Person016 p1("aaa", 10);
    Person016 p2("bbb", 20);
    Person016 p3("ccc", 30);
    Person016 p4("ddd", 40);
    Person016 p5("eee", 50);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);
    //遍历容器
    for (vector<Person016*>::iterator it = v.begin(); it != v.end(); it++) {
        // (*it)  是一个 <person016 *>  类型的数据类型  是一个指针 
        Person016* p = (*it);
        cout << "test01602 ：：Name:" << p->m_Name << " test01602 ：：Age:" << (*it)->m_Age << endl;
    }
}
int main016() {
    test01601();
    test01602();



    system("pause");
    return 0;
}