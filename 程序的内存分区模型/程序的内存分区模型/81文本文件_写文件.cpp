#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//�ı��ļ�  д�ļ�
// ���Գ���Ϊ����ģ���д�ļ��Ǵӳ���д���ı����ӳ���������ı���  ���ļ��Ǵ��ı�������򣨴��ı����뵽����
/*
* д�ļ���������裺
    1. ����ͷ�ļ�
        #include <fstream>
    2. ����������
        ofstream ofs;
    3.. ���ļ�
        ofs.open("�ļ�·��",�򿪷�ʽ);
    4. д����
        ofs << "д�������";
    5. �ر��ļ�
        ofs.close();
*/
void test8101() {
    //1. ����ͷ�ļ�   #include <fstream>
 
    //2.����������
    //д�ļ�----����������������Ǵӱ�����ָ��Ҫд���ļ�--������ output file stream
    ofstream write_file;

    //3.���ļ�   �򿪷�ʽ----д
    write_file.open("test.txt", ios::out);

    //4.д����
    write_file << "����������" << endl;
    write_file << "���䣺40" << endl;
    write_file << "�Ա�Ů" << endl;

    //�ر��ļ�
    write_file.close();


}

int main81() {


    test8101();

    system("pause");
    return 0;
}