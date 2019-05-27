#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, MAX= 0;
	int arr[1001] = {};
	int dp[1001] = {};
	
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	if (N == 1) {
		printf("%d\n",arr[0]);
		return 0;
	}
	for (int i = 0; i < N; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j]+arr[i]>dp[i]) {
				dp[i] = dp[j] + arr[i];
			}
		}
		MAX = max(MAX, dp[i]);
	}
	printf("%d\n", MAX);
	return 0;
} 
