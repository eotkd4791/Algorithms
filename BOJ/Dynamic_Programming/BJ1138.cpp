#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
vector<vector<int>> v(1005);
queue<int> q;
int N, M, V, a, b, visited[1005];

void DFS (int now) {
	visited[now] = 1;
	printf("%d ", now);
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[i] == 0) DFS(next);
	}
}

void BFS(int start) {
	visited[start] = 1;
	q.push(start);
	while (q.empty() == 0) {
		int now = q.front();
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (visited[i] == 0) {
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		sort(v[i].begin(), v[i].end());
	}
	DFS(V);
	printf("\n");
	memset(visited, 0, sizeof(visited));
	BFS(V);
	return 0;
}  
