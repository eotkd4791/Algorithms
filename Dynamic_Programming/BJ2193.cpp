#include <iostream>
#include <cstring>
using namespace std;
int N;
long long dp[91];

long long pinary(int n) {
	if (n <= 2) return 1;
	long long &ret = dp[n];
	if (ret > 0) return ret;
	ret = 0;
	return ret = pinary(n - 2) + pinary(n - 1);
}
int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &N);
	printf("%lld\n", pinary(N));
	return 0;
}
