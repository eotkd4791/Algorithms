//////////////////////////////////
/*
       BOJ2839 º≥≈¡ πË¥ﬁ
                                */
//////////////////////////////////
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int N;
int MIN = INF;

void sugar(int dgt, int cnt) {
	if (dgt == 0) {
		MIN = min(MIN, cnt);
		return;
	}
	if (0 < dgt && dgt < 3) {
		sugar(dgt + 5, cnt - 1);
	}
	else {
		if (dgt % 3 == 0) {
			int cc = cnt + (dgt / 3);
			sugar(0, cc);
		}
		else {
			if (dgt == N && cnt == 0) 
				return;
			sugar(dgt + 5, cnt - 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	sugar(N % 5, N / 5);
	int ans = -1;
	if (MIN != INF)
		ans = MIN;
	cout << ans;
	return 0;
}