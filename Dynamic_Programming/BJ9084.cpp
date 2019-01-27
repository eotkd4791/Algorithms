#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T = 0;
	int N,M = 0;
	int coin[30] = {};
	int dp[10010] = {};

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		dp[0] = 1;
		scanf("%d", &N);
		for (int j = 1; j <= N; j++) {
			scanf("%d", &coin[j]);
		}
		scanf("%d", &M);
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k <= M; k++) {
				if (coin[j] > k) dp[k] = dp[k];
				else {
					if (coin[j] <= k) dp[k] += dp[k - coin[j]];
				}
			}
		}
		printf("%d\n", dp[M]);
		memset(coin, 0, sizeof(coin));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}