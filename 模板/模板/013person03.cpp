#include"013person013.h"

// 构造函数 类外实现
template<class T1, class T2>
Person013<T1, T2>::Person013(T1 name, T2 age) {
    this->m_Name = name;
    this->m_Age = age;
}
//成员函数 类外实现
template<class T1, class T2>
void Person013<T1, T2>::showPerson013() {
    cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}