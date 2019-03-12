/*반쪽짜리 알약과 완전한 알약의 갯수를 조건에 맞춰서 집어넣고 
재귀를 호출하는 식으로 풀었다.*/
#include <iostream>
#include <cstring>
using namespace std;

int N;
long long dp[35][35];

long long pill(int w, int h) {
	long long &ret = dp[w][h];
	if (ret != 0) return ret;
	if (w == 0 && h == 0) return 1;
	if (w != 0) ret = pill(w - 1, h + 1);
	if (h != 0) ret += pill(w, h - 1);
	return ret;
}

int main() {
	while (1) {
		scanf("%d", &N);
		if (N == 0) break;
		printf("%lld\n", pill(N, 0));
		memset(dp, 0, sizeof(dp));
	}
	return 0;
}