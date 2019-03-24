/*
===================================
  BOJ2961 도영이가 만든 맛있는 음식
===================================

////////////////////////////////////////////////////////////////////
1가지 뽑는 경우의 수부터 ~ N가지를 뽑는 경우의 수를 조합함수로 계산했고
조합함수의 출력값과 같은 횟수로 계산을 했다.
stn은 뽑아야하는 갯수값.
cnt는 내가 지금까지 뽑은 갯수
/////////////////////////////////////////////////////////////////////
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int INF = 0xFFFFFFF;
int N;
int ech; //stn만큼 뽑아서 계산한 횟수를 세는 용, 조합출력값과 같아지면 stn+1해서 기준을 +1한다.
int s[11], b[11];
int MIN = INF;
bool pick[11];

int cb(int n, int k) {
	int dp[11][11] = {};
	int &ret = dp[n][k];
	if (k == 1) return n;
	if (n == k) return 1;
	if (k == 0) return 1;
	if (ret > 0) return ret;
	ret = 0;
	ret = cb(n - 1, k - 1) + cb(n - 1, k);
	return ret;
}//조합 함수를 만들어서 경우의 수 뽑아서 뽑아야 되는 수의 갯수 올리기 

void recur(int idx, int cnt, int stn) {//중복피하기 위한 인덱스 표시, 중복없이 뽑기위한 배열,지금까지 뽑은 수
	long long ans = 0;

	if (cnt == stn) {
		long long res = 1, reb = 0;
		ech++;
		for (int i = 1; i <= N; i++) {
			if (pick[i]) {
				res *= s[i];
				reb += b[i];
			}
		}
		
		ans = abs(res - reb);
		if (MIN > ans) MIN = ans;


		int C = cb(N, stn);
		if (ech == C) {
			ech = 0;
			memset(pick, 0, sizeof(pick));
			recur(1, 0, stn + 1);
		}
		return;
	}

	for (int i = idx; i <= N; i++) {
		if (!pick[i]) {
			pick[i] = 1;
			recur(i + 1, cnt + 1, stn);
			pick[i] = 0;
		}
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &s[i], &b[i]);
	}
	recur(1, 0, 1);
	printf("%d\n", MIN);
	return 0;
}