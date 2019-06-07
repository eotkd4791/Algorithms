///////////////////////////////////
/*
        BOJ1005 ACM Craft
*/
///////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ii = 1;

void DFS_tpl(vector<vector<int> > &v, int* ind, int* color, int* tpl, int idx) {
	color[idx] = 1;
	int sz = v[idx].size();
	for (int j = 0; j < sz; j++) {
		int idc = v[idx][j];
		if (color[idc] == 0)
			DFS_tpl(v, ind, color, tpl, idc);
	}
	tpl[ii++] = idx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<vector<int> > v;
		vector<vector<int> > r;
		v.resize(n + 1);
		r.resize(n + 1);
		int d[n + 1] = {};
		int color[n + 1] = {};
		int dp[n + 1] = {};
		int ind[n + 1] = {};
		int tpl[n + 1] = {};

		for (int i = 1; i <= n; i++)
			cin >> d[i];
			
		int a, b, w;
		for (int i = 1; i <= k; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			r[b].push_back(a);
			ind[b]++;
		}
		
		cin >> w;
		
		ii = 1;
		for (int i = 1; i <= n; i++) 
			if (ind[i] == 0 || color[i]==0)
				DFS_tpl(v,ind, color, tpl, i);
		
		reverse(tpl+1,tpl+n+1);
		dp[tpl[1]] = d[tpl[1]];
		
		for (int i = 1; i <= n; i++) {
			int rz=r[tpl[i]].size();
			if(rz==0)
				dp[tpl[i]] = d[tpl[i]];
			else {
				dp[tpl[i]]=d[tpl[i]];
				for(int j=0; j<rz; j++) {
					int tmp = r[tpl[i]][j];
					dp[tpl[i]] = max(dp[tpl[i]],dp[tmp]+d[tpl[i]]);
				}
			}
		}
		cout << dp[w] << '\n';
	}
	return 0;
}
