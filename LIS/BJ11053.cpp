/*LIS(Longest Increasing Subsequence)최장증가부분수열의
전형적이고 가장 쉬운 유형이지만 N이 1일때의 조건을 못잡아서
계속 틀렸다. 이 조건 통째로 공부해야겠다.*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, MAX = 0;
	int arr[1001] = {};
	int dp[1001] = {};

	dp[0] = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 1; i < N; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		MAX = max(MAX, dp[i]);
	}
	printf("%d\n", MAX);
	return 0;
}