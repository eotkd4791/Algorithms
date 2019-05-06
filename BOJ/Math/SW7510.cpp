/////////////////////////////////////
/*
	SWEA7510 상원이의 연속 합 

////////////////////////////////////
*/
#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main() {

	int t, n;
	scanf("%d", &t);

	for (int T = 1; T <= t; T++) {
		scanf("%d", &n);
		queue<int> q;
		int	cnt = 1;
		int sum = 0;

		for (int i = 1; i <= n; i++) {
			if (sum <= n) {
				if (sum == n) cnt++;
				sum += i;
				q.push(i);
			}
			if(sum > n) {
				while (sum > n) {
					int dgt = q.front();
					sum -= dgt;
					q.pop();
				}
			}
		}
		printf("#%d %d\n", T, cnt);

	}
	return 0;
}
