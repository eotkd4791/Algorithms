/*LIS의 길이를 학생 수에서 빼고, 학생수가 2명일 때의 조건을 세워서 간단하게 풀 수 있었다.*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N,len = 0;
	int arr[201] = {};
	int dp[201] = {};

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	if (N == 2) {
		if (arr[0] > arr[1]) printf("1\n");
		else printf("0\n");
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
		len = max(len, dp[i]);
	}
	printf("%d\n", N - len);
	return 0;
}