///////////////////////////
/*
    BOJ2309 일곱 난쟁이
                         */
///////////////////////////
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int arr1[9] = {}; // 입력받는 배열
	int arr2[7] = {}; // 일곱 난쟁이만 넣는 배열
	int x, y = 0;
	int sum = 0;
	int rest = 0;

	for (int i = 0; i < 9; i++) {
		scanf_s("%d", &arr1[i]);
		sum += arr1[i];
	}

	rest = sum - 100;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr1[j] == rest - arr1[i]) {
				x = arr1[i];
				y = arr1[j];
			}
		}
	}

	for (int i = 0; i < 9; i++) {
			if (arr1[i] != x && arr1[i] != y)
				arr2[i] = arr1[i];
	}

	sort(arr2,arr2+7);
	for (int i = 0; i < 7; i++) {
		printf("%d\n", arr2[i]);
	}
	return 0;
} 
