#include <iostream>
#include <cstring>
using namespace std;

long long dp[70];

long long koong(int n) {
	if (n < 2) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;
	long long &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	return ret = koong(n - 1) + koong(n - 2) + koong(n - 3) + koong(n - 4);
}

int main() {
	int t = 0;
	int n = 0;
	memset(dp, -1, sizeof(dp));
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		printf("%lld\n", koong(n));
	}
	return 0;
}