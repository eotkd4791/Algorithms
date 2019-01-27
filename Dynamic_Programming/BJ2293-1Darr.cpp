/*동전의 가치가 k값보다 작으면 원래 dp배열에 저장되어 있던 내용을 그대로 놔두고,
동전의 가치가 k값보다 크다면 k-동전의 가치한 값을 인덱스로 가져와서 내용을 갱신하였다.*/
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
