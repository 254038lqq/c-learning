#include<iostream>
using namespace std;
//ð��������  ����1 ������׵�ַ  ����2 ���鳤��
void bubbluesort(int* arr, int len) {
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}
void printarr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}

}

int main() {

	//ָ��ͺ���
	// ��װһ������������ð������ʵ�ֶ������������������
	// 
	//1.����һ������
	int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//����������ʵ������
	bubbluesort(arr, len);

	//��ӡ���������
	printarr(arr, len);

	system("pause");
	return 0;
}