#include<iostream>
using namespace std;
//冒泡排序函数  参数1 数组的首地址  参数2 数组长度
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

	//指针和函数
	// 封装一个函数，利用冒泡排序，实现对整数数组的升序排序
	// 
	//1.创建一个数组
	int arr[] = { 4,3,6,9,1,2,10,8,7,5 };
	int len = sizeof(arr) / sizeof(arr[0]);

	//创建函数，实现排序
	bubbluesort(arr, len);

	//打印排序后的输出
	printarr(arr, len);

	system("pause");
	return 0;
}