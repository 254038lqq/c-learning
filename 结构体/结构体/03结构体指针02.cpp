#include<iostream>
#include<string>
#include<algorithm> // 包含标准库中的排序函数
using namespace std;

// 定义结构体
struct Student {
    string name;
    int age;
    int score;
};

// 自定义比较函数，用于排序
bool compareByAge(const Student& a, const Student& b) {
    return a.age < b.age; // 按照年龄升序排序
}

int main() {
    // 创建结构体数组
    Student s[2] = { {"张三", 19, 100}, {"李四", 12, 90} };

    // 通过指针指向结构体数组的首地址
    Student* p = s;

    // 通过指针访问结构体变量中的数据
    cout << "排序前的结构体数组：" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "姓名：" << p[i].name << "  年龄：" << p[i].age << "  分数：" << p[i].score << endl;
    }

    // 对结构体数组按照年龄进行排序
    sort(s, s + 2, compareByAge);

    // 打印排序后的结果
    cout << "\n按年龄排序后的结构体数组：" << endl;
    for (int i = 0; i < 2; ++i) {
        cout << "姓名：" << s[i].name << "  年龄：" << s[i].age << "  分数：" << s[i].score << endl;
    }
    system("pause");
    return 0;
}
