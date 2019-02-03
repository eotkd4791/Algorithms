#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
queue<pair<int, int>>q;
vector<vector<int>>v(5001);
int N, M, a, b, sum, cnt, MIN = 987654321;
int check[5001], arr[101];

int BFS(int start) {
	check[start] = 1;
	q.push({ start,0 });
	while (q.empty() == 0) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		sum += cnt;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (check[next] == 0) {
				check[next] = 1;
				q.push({ next,cnt + 1 });
			}
		}
	}
	return sum;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= N; i++) {
		arr[i] = BFS(i);
		MIN = min(MIN, BFS(i));
		sum = 0;
		memset(check, 0, sizeof(check));
	}
	for (int i = 1; i <= N; i++) {
		if (arr[i] == MIN) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}
