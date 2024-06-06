#include<iostream>
using namespace std;
void test01(int arr[],int len) {
	
	for (int i = 0; i < len; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (i != min) {
			int tem = arr[i];
			arr[i] = arr[min];
			arr[min] = tem;
		}

	}

}
int main() {

	int arr[5] = { 3,6,4,2,5 };
	int length = sizeof(arr) / sizeof(arr[0]);
	test01(arr, length);

	cout << "输出排序后的数组：" << endl;
	for (int i = 0; i < length; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}