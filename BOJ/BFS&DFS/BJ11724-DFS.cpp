#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
queue<int>q;
vector<vector<int>> r(105);
int n, m, a, b, check[105],target1,target2, cnt;

void DFS(int mem1,int mem2) {
	check[mem1] = 1;	
	for (int i = 0; i < r[mem1].size(); i++) {
		int mem2 = r[mem1][i];
		if (check[mem2] == 0) {
			cnt++;
			DFS(mem2,mem1);
		}
		if (r[mem1][i] != mem2) {
			printf("-1\n");
			return;
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%d%d", &target1, &target2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		r[a].push_back(b);
		r[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		sort(r[i].begin(), r[i].end());
	}
	DFS(target1,target2);
	printf("%d\n", cnt);
	return 0;
}