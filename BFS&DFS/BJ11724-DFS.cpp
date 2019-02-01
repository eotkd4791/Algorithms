#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<vector<int>> cn(1005);
int N, M, u, v, check[1005], cnt;

void DFS(int now) {
	if (check[now] != 0) return;
	check[now] = 1;	
	for (int i = 0; i < cn[now].size(); i++) {
		int next = cn[now][i];
		if (check[next] == 0) DFS(next);
		
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
		DFS(i);
	}
	printf("%d\n", cnt);
	return 0;
}