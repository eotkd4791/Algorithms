#include <iostream>
#include <algorithm>
using namespace std;
int arr1[9],arr2[9],tmp;
int main() {
	for (int i = 0; i < 9; i++) {
		scanf("%d", &arr1[i]);
		arr2[i] = arr1[i];
	}
	sort(arr1, arr1 + 9);
	for (int i = 0; i < 9; i++) {
		if (arr1[8] == arr2[i]) tmp = i+1;
	}
	printf("%d\n%d\n", arr1[8], tmp);
	return 0;
}