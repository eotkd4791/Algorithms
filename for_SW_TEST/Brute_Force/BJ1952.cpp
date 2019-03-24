/*
=========================
      SW1952 수영장
=========================

//////////////////////////////////////
1일이용권과 1달이용권 중, 최솟값이 되는
요금을 dp에 저장한 후, 세달이용권과의 가격을
비교하면서 월별 최솟값을 dp를 채워나갔다.
마지막에는 1년 이용권과 dp[11]값을 비교하여
최솟값이 되는 것을 출력하였다.
//////////////////////////////////////
*/

#include <iostream>
#include <algorithm>
using namespace std;

int T, N;
int cost[4];
int month[12];
int mprice[12];
int dp[12];

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < 4; i++) scanf("%d", &cost[i]);
		for (int i = 0; i < 12; i++) scanf("%d", &month[i]);
		for (int i = 0; i < 12; i++) {
			mprice[i] = min(cost[1], cost[0] * month[i]);
		}
		dp[0] = mprice[0];
		for (int i = 1; i < 12; i++) {
			if (i < 2) dp[i] = dp[i - 1] + mprice[i];
			else {
				dp[i] = min(mprice[i]+dp[i-1], cost[2] + dp[i - 3]);
			}
		}
		int MIN = min(dp[11], cost[3]);
		printf("#%d %d\n", t, MIN);
	}
}