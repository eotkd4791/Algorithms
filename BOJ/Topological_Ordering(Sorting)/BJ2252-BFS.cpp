/////////////////////////////////////
/*
	BOJ2252 줄 세우기 (BFS)

/////////////////////////////////////

BFS로 위상정렬 구현
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int ii;
int ans[32001];
int ind[32001];
vector<vector<int> > v(32001);
queue<int> q;

void BFS() {
	while (!q.empty()) {
		int oq = q.front();
		int sz = v[oq].size();
		for (int i = 0; i < sz; i++) {
			int w = v[oq][i];
			ind[w]--;
			if (ind[w] == 0) q.push(w);
		}
		q.pop();
		ans[ii++] = oq;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		ind[b]++;
	}
	for (int i = 1; i <= N; i++)
		if (ind[i] == 0) q.push(i);
	BFS();
	for (int i = 0; i < N; i++)
		cout << ans[i] << ' ';
	return 0;
}
