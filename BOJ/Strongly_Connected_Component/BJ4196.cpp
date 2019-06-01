//////////////////////////////////////////
/*
            BOJ4196 µµ¹Ì³ë
                                        */
//////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
#include <utility>
#define INF 100001
using namespace std;

vector<vector<int> > adj;
stack<int> s;
int dT[INF];
int fT[INF];
pair<int,int> scc[INF];
int time;
int check[INF];
int low[INF];
int gnum;

void dfsSCC(int v) {
	check[v] = 1;
	dT[v] = ++time;
	s.push(v);
	low[v] = dT[v];

	int sz = adj[v].size();
	for (int i = 0; i < sz; i++) {
		int w = adj[v][i];

		if (check[w] == 0) {
			dfsSCC(w);
			low[v] = min(low[v], low[w]);
		}

		if (check[w] == 1) {
			low[v] = min(low[v], dT[w]);
		}

		if (check[w] == 2) {
			if (dT[v] < dT[w]) 
				continue;

			else if (fT[w] < dT[v]) {
				if (scc[w].first == 0) {
					low[v] = min(low[v], low[w]);
				}
				else
					continue;
			}
		}
	}

	fT[v] = ++time;
	check[v] = 2;
	if (low[v] == dT[v]) {
		gnum++;
		while (1) {
			int st = s.top();
			scc[st].first = st;
			scc[st].second = gnum;
			s.pop();
			if (st == v)
				break;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int T, N, M;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> M;
		adj.resize(N + 1);

		int x, y;
		for (int i = 0; i < M; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
		}

		for (int i = 1; i <= N; i++) 
			if(check[i]==0)
				dfsSCC(i);

		int cnt = 0;
		int outd[INF] = {};
		for (int i = 1; i <= N; i++) {
			int ss = adj[i].size();
			for (int j = 0; j < ss; j++) {
				int tmp = adj[i][j];
				if(scc[i].second != scc[tmp].second)
					outd[scc[tmp].second]++;
			}
		}
	
		for (int i = 1; i <= gnum; i++) {
			if (outd[i] == 0)
				cnt++;
		}

		cout << cnt << "\n";
		gnum = 0;
		memset(check, 0, sizeof(check));
		memset(low, 0, sizeof(low));
		memset(scc, 0, sizeof(scc));
		for (int i = 1; i <= N; i++) {
			adj[i].clear();
		}
		time = 0;
	}
	return 0;
}