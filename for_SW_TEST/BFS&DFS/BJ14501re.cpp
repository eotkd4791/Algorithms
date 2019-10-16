#include <iostream>
#include <algorithm>
using namespace std;

int N;
int T[16];
int P[16];
bool check[16];
int MAX;

void dfs(int day, int pay) {
	if (day > N + 1)
		return;
	
	MAX = max(MAX, pay);

	for (int idx = day; idx <= N; idx++) {
		if (!check[idx]) {
			check[idx] = 1;
			dfs(idx + T[idx],  pay + P[idx]);
			check[idx] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> T[i] >> P[i];
	
	dfs(1, 0);
	cout << MAX;
	return 0;
}