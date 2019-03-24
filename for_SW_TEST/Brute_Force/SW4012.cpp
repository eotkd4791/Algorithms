/*
================================
         SW4012 요리사
================================
////////////////////////////////
재귀의 흐름을 파악하면 충분히 풀 수
있는 문제였다.
나중에 다시한번 풀어보고 익숙해지자
////////////////////////////////
*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#define h N/2
using namespace std;

const int INF = 0xFFFFFFF;
int T, N, s[20][20];
bool isused[20];
int MIN = INF;
int ans;

void recur(int idx, int cnt) {
	if (cnt == h) {
		int result1 = 0; int result2 = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {

				if (isused[i] && isused[j]) {
					result1 += s[i][j];
				}
				if (!isused[i] && !isused[j]) {
					result2 += s[i][j];
				}
			}
		}
		ans = abs(result1 - result2);
		MIN = min(MIN, ans);
		return;
	}
	for (int i = idx; i <= N; i++) {
		isused[i] = 1;
		recur(i + 1, cnt + 1);
		isused[i] = 0;
	}
}

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				scanf("%d", &s[i][j]);
			}
		}
		recur(0, 0);
		printf("#%d %d\n", t, MIN);
		memset(isused, 0, sizeof(isused));
		memset(s, 0, sizeof(s));
		MIN = INF;
	}
	return 0;
}