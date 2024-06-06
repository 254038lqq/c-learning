#include<iostream>
#include<string>
using namespace std;

//继承的基本语法

//普通实现页面
//Java页面 
class Java6501 {
public: 
    void header() { 
        cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
    } 
    void footer() { 
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
    } 
    void left() { 
        cout<< "Java,Python,C++...(公共分类列表)" << endl; 
    } 
    void content() { 
        cout << "JAVA学科视频" << endl; 
    } 
};
//Python页面 
class Python6501 { 
public: 
    void header() { 
        cout << "首页、公开课、登录、注册...（公共头部）" << endl; 
    } 
    void footer() { 
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
    }
    void left() { 
        cout<< "Java,Python,C++...(公共分类列表)" << endl; 
    } 
    void content() {
        cout << "Python学科视频" << endl; 
    }
};
//C++页面 
class CPP6501 { 
public: 
    void header() { 
        cout << "首页、公开课、登录、注册...（公共头部）" <<endl; 
        } 
    void footer() { 
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl; 
    } 
    void left() {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    } 
    void content() { 
        cout << "C++学科视频" << endl; 
    } 
};
void test6501() {
    //Java页面 
    cout << "Java下载视频页面如下： " << endl;
    Java6501 ja6501;
    ja6501.header();
    ja6501.footer();
    ja6501.left();
    ja6501.content();
    cout << "--------------------" << endl;

    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python6501 py6501;
    py6501.header();
    py6501.footer();
    py6501.left();
    py6501.content();
    cout << "--------------------" << endl;

    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP6501 cp6501;
    cp6501.header();
    cp6501.footer();
    cp6501.left();
    cp6501.content();

}

//继承实现页面
//公共页面 
class BasePage65 {
public:
    void header() {
        cout << "首页、公开课、登录、注册...（公共头部）" << endl;
    }
    void footer()
    {
        cout << "帮助中心、交流合作、站内地图...(公共底部)" << endl;
    }
    void left()
    {
        cout << "Java,Python,C++...(公共分类列表)" << endl;
    }
};
//Java页面 
class Java6502 : public BasePage65 { 
public: 
    void content() { 
        cout << "JAVA学科视频" << endl; 
    } 
};
//Python页面 
class Python6502 : public BasePage65 { 
public: 
    void content() 
    { 
        cout << "Python学科视频" << endl;
    }
}; 
//C++页面 
class CPP6502 : public BasePage65 {
public: 
    void content() {
        cout << "C++学科视频" << endl;
    } 
};
void test6502() {
    //Java页面 
    cout << "Java下载视频页面如下： " << endl;
    Java6502 ja6502;
    ja6502.header();
    ja6502.footer();
    ja6502.left();
    ja6502.content();
    cout << "--------------------" << endl;

    //Python页面
    cout << "Python下载视频页面如下： " << endl;
    Python6502 py6502;
    py6502.header();
    py6502.footer();
    py6502.left();
    py6502.content();
    cout << "--------------------" << endl;
    //C++页面
    cout << "C++下载视频页面如下： " << endl;
    CPP6502 cp6502;
    cp6502.header();
    cp6502.footer();
    cp6502.left();
    cp6502.content();
}
int main65() {

    //test6501();
    test6502();


    system("pause");
    return 0;
}