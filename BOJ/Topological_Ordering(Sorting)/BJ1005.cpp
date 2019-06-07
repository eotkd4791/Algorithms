//////////////////////////////
/*
    BOJ1005 ACM Craft
			    */
//////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

vector<vector<int> > v;
vector<vector<int> > inv;
queue<int> q;
int d[100001];
int dp[1001];
int ind[1001];
int tpl[1001];
bool check[1001];

void BFS() {
	int ii = 1;
	while (!q.empty()) {
		int oq = q.front();
		check[oq] = 1;
		q.pop();
		int sz = v[oq].size();
		for (int j = 0; j < sz; j++) {
			int idx = v[oq][j];
			ind[idx]--;
			if (ind[idx] == 0 && !check[idx]) {
				check[idx] = 1;
				q.push(idx);
			}
		}
		tpl[ii++] = oq;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, w;
		cin >> n >> k;

		v.resize(n + 1);
		inv.resize(n + 1);
		for (int i = 1; i <= n; i++) 
			cin >> d[i];
		

		int a, b;
		for (int i = 0; i < k; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			inv[b].push_back(a);
			ind[b]++;
		}
		cin >> w;
		for (int i = 1; i <= n; i++)
			if (ind[i] == 0)
				q.push(i);
		BFS();

		for (int i = 1; i <= n; i++) {
			int iz = inv[tpl[i]].size();
			if (inv[tpl[i]].size() == 0) {
				dp[tpl[i]] = d[tpl[i]];
			}
			else {
				dp[tpl[i]] = d[tpl[i]];
				for (int j = 0; j < iz; j++) {
					dp[tpl[i]] = max(dp[tpl[i]], dp[inv[tpl[i]][j]] + d[tpl[i]]);
				}
			}
		}
		cout << dp[w] << '\n';

		v.clear();
		inv.clear();
		memset(dp, 0, sizeof(dp));
		memset(tpl, 0, sizeof(tpl));
		memset(check, 0, sizeof(check));
	}
	return 0;
}
