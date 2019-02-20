/*SW2071 평균값 구하기 문제
내림함수를 이용하여 반올림을 구현하고,
출력시 소수자릿수를 지우고 출력하였다.*/
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int T, arr[10]; double sum;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &arr[j]);
			sum += arr[j];
		}
		printf("#%d %.0lf\n", i, floor((sum / 10) + 0.5));
		sum = 0;
		memset(arr, 0, sizeof(arr));
	}
	return 0;
}