//////////////////////////////////
/*
     BOJ1516 게임 개발 (BFS)
*/
//////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
int d[501];
int ind[501];
int tpl[501];
int dp[501];
vector<vector<int> >v;
queue<int> q;
int ii = 1;

void BFS() {
	while (!q.empty()) {
		int vv = q.front();
		q.pop();
		int sz = v[vv].size();
		for (int j = 0; j < sz; j++) {
			int ww = v[vv][j];
			dp[ww] = max(dp[vv] + d[ww], dp[ww]);
			ind[ww]--;
			if (ind[ww] == 0)
				q.push(ww);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n + 1);

	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		dp[i] = d[i];
		int a = 0;
		while (1) {
			cin >> a;
			if (a == -1)
				break;
			v[a].push_back(i);
			ind[i]++;
		}
	}

	for (int i = 1; i <= n; i++)
		if (ind[i] == 0)
			q.push(i);
	BFS();

	for (int i = 1; i <= n; i++)
		cout << dp[i] << '\n';
	return 0;
}
