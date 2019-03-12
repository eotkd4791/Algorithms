/*<cstring>STL의 memset함수를 이용하여 풀어 보았다.*/
#include <iostream>
#include <cstring>

using namespace std;
long long dp[110];

long long P(int n) {
	if (n <= 3) return 1;
	long long &ret = dp[n];
	if (ret != -1) return ret;
	ret = 0;
	return ret = P(n - 2) + P(n - 3);
}

int main() {
	int T = 0;
	int N = 0;
	
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &N);
		printf("%lld\n",P(N));
	}
	return 0;
}