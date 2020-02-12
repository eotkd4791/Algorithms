#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M;
vector<vector<int> > adj;
const int MAX_N = 100000;
const int MAX_G = 20;
int depth[MAX_N + 1];
int ancestor[MAX_N + 1][MAX_G];

void getDepth() {
	queue<int> q;
	q.push(1);
	depth[1] = 1;
	ancestor[1][0] = 0;

	while (!q.empty()) {
		int oq = q.front();
		q.pop();
		
		int vs = adj[oq].size();
		for (int i = 0; i < vs; i++) {
			int nq = adj[oq][i];
			if (depth[nq] == 0) {
				depth[nq] = depth[oq] + 1;
				ancestor[nq][0] = oq;
				q.push(nq);
			}
		}
	}
}

void getAncestor() {
	for (int j = 0; j < MAX_G; j++) 
		for (int i = 1; i <= N; i++) 
			if (ancestor[i][j] != 0) 
				ancestor[i][j + 1] = ancestor[ancestor[i][j]][j];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin >> N;
	adj.resize(N + 1);

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	getDepth();
	getAncestor();

	cin >> M;
	while (M--) {
		cin >> a >> b;

		if (depth[a] < depth[b]) swap(a, b);
		int diff = depth[a] - depth[b];

		for (int j = 0; diff != 0; j++) {
			if (diff % 2 == 1) a = ancestor[a][j];
			diff /= 2;
		}

		if (a != b) {
			for (int j = MAX_G - 1; j >= 0; j--) {
				if (ancestor[a][j] != 0 && ancestor[a][j] != ancestor[b][j]) {
					a = ancestor[a][j];
					b = ancestor[b][j];
				}
			}
			a = ancestor[a][0];
		}
		cout << a << '\n';
	}
	return 0;
}