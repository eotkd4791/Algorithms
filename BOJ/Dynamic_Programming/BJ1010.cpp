//-다리놓기-
//N<=M 조합nCk에서 n=M,k=N
//조합공식을 nPk/k!으로 구현했지만, 시간초과가 났다.
//그래서 이항계수 공식을 이용한 DP로 구현하였다.

#include <iostream>
#include <cstring>
using namespace std;
int T, N, M;
long long dp[30][30];

long long cmb(int n, int k) {
	long long &ret = dp[n][k];
	if (k == 1) return n;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (ret > 0) return ret;
	ret = 0;
	ret = cmb(n - 1, k - 1) + cmb(n - 1, k);
	return ret;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &N, &M);
		printf("%lld\n", cmb(M,N));
	}
	return 0;
} 
