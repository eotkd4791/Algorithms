#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
vector<vector<int>> r(101);
queue<pair<int, int>>q;
int n, m, x, y, target1, target2, check[101];

int BFS(int start) {
	check[start] = 1;
	q.push({ start, 0 });
	while (q.empty() == 0) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (now == target2) return cnt;
		for (int i = 0; i < r[now].size(); i++) {
			int next = r[now][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return -1;

}
int main() {
	scanf("%d", &n);
	scanf("%d%d", &target1, &target2);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		r[x].push_back(y);
		r[y].push_back(x);
	}
	printf("%d\n", BFS(target1));
	return 0;
}