#include <iostream>
using namespace std;

int main() {
	int dp[1001], arr[1001] = {};
	int n, MAX = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
			
		}
		if (MAX < dp[i]) MAX = dp[i];
	}
	printf("%d\n", MAX);
	return 0;
} 
