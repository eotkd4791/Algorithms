///////////////////////////////
/*
    BOJ1707 이분 그래프 
                            */
///////////////////////////////
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;
vector<vector<int> > v(20001);
int check[20001];
int V, E, K;
int cnt = 1;

void DFS(int idx, int start) {
	check[idx] = start;
	for (int i = 0; i < v[idx].size(); i++) {
		int ii = v[idx][i];
		if (check[ii] == 0) {
			if (start == 1) {
				DFS(ii, 2);

			}
			else {
				DFS(ii, 1);
			}
		}
	}
}

bool yes_or_no() {
	for (int i = 1; i <= V; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			int idx = v[i][j];
			if (check[i] == check[idx]) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> K;
	for (int k = 1; k <= K; k++) {
		memset(check, 0, sizeof(check));
		for (int i = 1; i <= V; i++) {
			v[i].clear();
		}
		cin >> V >> E;

		int a, b;
		for (int i = 1; i <= E; i++) {
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= V; i++) {
			if (check[i] == 0) DFS(i, 1);
		}
		if (yes_or_no()) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
