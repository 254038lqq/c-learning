/*
* ===================== ����1��============================
* ==================== �������� ============================
*     ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���������ʦ���������£�
*  ���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
*  ѧ���ĳ�Ա�����������Է���������������������ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
*  ���մ�ӡ����ʦ�����Լ���ʦ������ѧ������
* 
*/

//  �����������쳣����ȡ����Ȩ�޳�ͻ
//  ԭ�� д��̫�����ͬ���ֵĽṹ��


#include<string>
#include<iostream>
using namespace std;

//ʱ���ͷ�ļ�
#include<Ctime>


// ����ѧ���ṹ��
struct student07 {
	string student_name;
	float student_score;
};
//������ʦ�ṹ��
struct teacher07 {
	string teacher_name;
	struct student07 stuarray[5];
};

//����ʦ��ѧ����ֵ�ĺ���
void allocatspace(struct teacher07 tarray[], int len_t ){
	string nameseed = "ABCDE";
	for (int i = 0; i < len_t; i++) {
		tarray[i].teacher_name = "teacher_";
		tarray[i].teacher_name += nameseed[i];

		//ͨ��ѭ������ʦ������ѧ����ֵ
		//float scoreseed[5] = {78, 79, 80, 81, 82};
		for (int j = 0; j < 5; j++) {
			tarray[i].stuarray[j].student_name = "student_";
			//tarray[i].stuarray[j].student_name += nameseed[j];
			tarray[i].stuarray[j].student_name.append(1,nameseed[j]);

			int rondom = rand() % 61 + 40; //40~99
			tarray[i].stuarray[j].student_score = rondom;
		}
	}
};
//��ӡ������Ϣ
void printinfo(struct teacher07 tarray[], int len_t) {
	for (int i = 0; i < len_t; i++) {
		cout << "��ʦ����" << tarray[i].teacher_name << endl;
		for (int j = 0; j < 5; j++) {
			cout << "\tѧ������" << tarray[i].stuarray[j].student_name <<
				",ѧ������" << tarray[i].stuarray[j].student_score << endl;

		}
	}
};
int main0701(){

	//���������
	/*
		srand((unsigned int)time(NULL)); ���д������ڳ�ʼ������������������ӡ�
		������ǰʱ�������ת��Ϊһ�� unsigned int ���͵�ֵ����������Ϊ srand() �����Ĳ������ݣ���ȷ��ÿ�γ�������ʱ���������ͬ����������С�
		����������Ϊ�����������ͨ����α����ģ����ǵ����ȡ�������ǵĳ�ʼ״̬����Ϊ���ӡ����ʹ����ͬ����������ʼ�������������������������ͬ�����С�
		ͨ������������Ϊ��ͬ��ֵ���統ǰʱ�䣬����ʹ��ÿ�����г���ʱ���õ���ͬ����������С�
	*/
	srand((unsigned int)time(NULL));
	//����������ʦ������
	struct teacher07 teaarray[3];
	//ͨ��������������ʦ����Ϣ��ֵ��������ʦ����ѧ����Ϣ��ֵ
	//��ȡ��ʦ�ĳ���
	int len_t = sizeof(teaarray) / sizeof(teaarray[0]);
	allocatspace(teaarray, len_t);

	//��ӡ������ʦ������ѧ����Ϣ
	printinfo(teaarray, len_t);
	system("pause");
	return 0;
}
