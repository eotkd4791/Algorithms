//////////////////////////////////
/*
      BOJ1516 게임 개발 (DFS)
*/
//////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int d[501];
int ind[501];
bool check[501];
int tpl[501];
int dp[501];
vector<vector<int> >v;
vector<vector<int> >r;
int ii = 1;

void DFS(int vv) {
	check[vv] = 1;
	int sz = v[vv].size();
	for (int j = 0; j < sz; j++) {
		int ww = v[vv][j];
		if (!check[ww])
			DFS(ww);
	}
	tpl[ii++] = vv;
}	

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	v.resize(n + 1);
	r.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		int a=0;
		while (1) {
			cin >> a;
			if (a == -1)
				break;
			v[a].push_back(i);
			r[i].push_back(a);
			ind[i]++;
		}
	}

	for (int i = 1; i <= n; i++) 
		if (!check[i] || ind[i] == 0)
			DFS(i);
	
	reverse(tpl + 1, tpl + n + 1);

	for (int i = 1; i <= n; i++) {
		int rz = r[tpl[i]].size();
		if (rz == 0)
			dp[tpl[i]] = d[tpl[i]];
		else {
			dp[tpl[i]] = d[tpl[i]];
			for (int j = 0; j < rz; j++) {
				int tmp = r[tpl[i]][j];
				dp[tpl[i]] = max(dp[tpl[i]], dp[tmp] + d[tpl[i]]);
			}
		}
	}
	for (int i = 1; i <= n; i++) 
		cout << dp[i] << '\n';
	return 0;
}
