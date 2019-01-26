#include <iostream>
using namespace std;

int n, k;
int dp[10010];
int coin[110];

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &coin[i]);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) dp[j] = 0;
			if (coin[i]<=dp[j]) {
				dp[j] = dp[j];				
			}
			else {
				dp[j] +=dp[j - coin[i]];
			}
		}
	}
	printf("%d\n", dp[k]);
	return 0;
}