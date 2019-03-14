/*
===========================
     SW Expert Academy
     간단한 3 6 9 게임
===========================

+++++++++++++++++++++++++++
빡구현으로 했지만, 바킹독님의
코드를 참고하니,
자리수 분해하고 3,6,9가 있으면
cnt++하고 while(cnt--)해서
박수를 출력하고
while문 빠져나오면서 " "출력
if (!cnt) cnt가 0일때는
그대로 값을 출력하게 하는
아이디어도 있었다.
모르는 함수 rep를 쓰셨다.

===========================
*/

#include <iostream>
#include <cstring>
using namespace std;

int N,arr[5];

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int tmp = i;
		int cnt = 0;
		memset(arr, 0, sizeof(arr));
		for (int j = 1; j <= 4; j++) {
			arr[j] = tmp % 10;
			tmp /= 10;
		}
		for (int j = 1; j <= 4; j++) {
			if (arr[j] == 3 || arr[j] == 6 || arr[j] == 9) printf("-");
		}
		for (int j = 1; j <= 4; j++) {
			if (arr[j] == 3 || arr[j] == 6 || arr[j] == 9) cnt++;
		}
		if (cnt > 0) {
			printf(" ");
			continue;
		}
		if (cnt == 0) {
			printf("%d ", i);
		}
	}
	return 0;
}