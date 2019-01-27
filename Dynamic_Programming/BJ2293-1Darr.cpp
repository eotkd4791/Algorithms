#include <iostream>
using namespace std;

int main() {
	int n, k = 0;
	int dp[10001] = {};
	int coin[101] = {};

	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (coin[i] > j) dp[j] = dp[j];
			else if (coin[i] <= j) dp[j] += dp[j - coin[i]];
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}