#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int score[1001];
int dp[1001];

int make_max(int result) {
	int &ret = dp[result];
	if (ret != -1) return ret;

	ret = 0;
	int MAX = 0;
	int MIN = 9999;
	for (int i = result; i <= N; i++) {
		MAX = max(MAX, score[i]);
		MIN = min(MIN, score[i]);
		ret = max(ret, make_max(i + 1) + MAX - MIN);
	}
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &score[i]);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", make_max(1));
}
