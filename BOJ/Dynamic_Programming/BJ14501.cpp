/*
============================
      BOJ14501 퇴사
============================
SW기출 
*/

#include <iostream>
#include <algorithm>
using namespace std;
int N;
int T[20];
int P[20];
int MAX = 0;

void money_max(int day, int pay) {
	MAX = max(MAX, pay);
	if (day == N + 1) return;
	if (day + T[day] <= N + 1) {
		money_max(day + T[day], pay + P[day]);
	}
	if (day + 1 <= N + 1) {
		money_max(day + 1, pay);
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &T[i], &P[i]);
	}
	money_max(1, 0);
	printf("%d", MAX);
	return 0;
}
