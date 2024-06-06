#include<iostream>
#include<string>.
#include<fstream>
using namespace std;

//�ı��ļ�  ���ļ�
// ���Գ���Ϊ����ģ���д�ļ��Ǵӳ���д���ı����ӳ���������ı���  ���ļ��Ǵ��ı�������򣨴��ı����뵽����
/*
* ���ļ����������
    1. ����ͷ�ļ�
        #include <fstream>
    2. ����������
        ifstream ifs;
    3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�
        ifs.open("�ļ�·��",�򿪷�ʽ);
    4. ������
        ���ַ�ʽ��ȡ
    5. �ر��ļ�
        ifs.close();
*/

void test8201() {
    //1.����ͷ�ļ�  #include <fstream>
    // 
    //2.����������   
    ifstream ifs;

    //3. ���ļ����ж��ļ��Ƿ�򿪳ɹ�   �򿪷�ʽ----��
    ifs.open("test.txt", ios::in);
    if (!ifs.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
    //4.������
    //��һ�ַ�ʽ   ���� ��������� �� ifs �е����� ȫ��д�뵽  �ַ�����  buf ��
    //char buf[1024] = { 0 };
    //while (ifs >> buf)
    //{
    // cout << buf << endl;
    //}
    //�ڶ���    ���� getline ��  ifs  �е����ݶ��뵽 �ַ����� buf ��,sizeof(buf)  ---������������
    //char buf[1024] = { 0 };
    //cout << sizeof(buf) << endl;
    //while (ifs.getline(buf,sizeof(buf)))
    //{
    //    cout << buf << endl;
    //}
    //������  ����  getline ������ ifs ���������ݶ�ȡ�� �ַ����� string buf ��
    //string buf;
    //while (getline(ifs, buf))
    //{
    // cout << buf << endl;
    //}
    //�����֣����Ƽ��ã�  һ��һ���ַ�  �Ľ�ifs  �е��������� ȫ�������ַ������� char ��
    // != EOF  ���û�ж����ļ�β   EOF  end of file  �ļ�β
    char c;
    while ((c = ifs.get()) != EOF)
    {
        cout << c ;
    }
    //5.�ر��ļ�
    ifs.close();
}
int main82() {


    test8201();

    system("pause");
    return 0;
}