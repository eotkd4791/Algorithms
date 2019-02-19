#include <iostream>
#include <algorithm>
using namespace std;
int arr1[7], arr2[7],sum,MIN=999999999;

int main() {
	for (int i = 0; i < 7; i++) {
		scanf("%d", &arr1[i]);
		if (arr1[i] % 2 == 1) {
			arr2[i] = arr1[i];
			sum += arr2[i];
		}
		if(arr2[i]!=0) MIN = min(MIN, arr2[i]);
	}
	if (sum == 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n", sum, MIN);
	return 0;
}