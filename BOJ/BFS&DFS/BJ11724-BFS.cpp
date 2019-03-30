#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> cn(1005);
queue<int>q;
int N, M, u, v, check[1005], cnt;

void BFS(int start) {
	if (check[start] != 0) return;
	check[start] = 1;
	q.push(start);
	while (q.empty() == 0) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < cn[now].size(); i++) {
			int next = cn[now][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &u, &v);
		cn[u].push_back(v);
		cn[v].push_back(u);
	}
	for (int i = 0; i < N; i++) {
		sort(cn[i].begin(), cn[i].end());
	}
	for (int i = 1; i <= N; i++) {
		if (check[i] == 0) cnt++;
		BFS(i);
	}
	printf("%d\n", cnt);
	return 0;
} 
