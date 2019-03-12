#include <iostream>
using namespace std;

long long dp[110];
int check[110];

long long P(int n) {
	if (n <= 3) return 1;
	if (n <= 5) return 2;
	if (check[n] != 0) return dp[n];
	dp[n] = P(n - 2) + P(n - 3);
	check[n] = 1;
	return dp[n];
}

int main() {
	int T = 0;
	int N = 0;

	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		printf("%lld\n",P(N));
	}
	return 0;
}