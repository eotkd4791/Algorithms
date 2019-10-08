//Prim's Algorithm
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;

int n, m;
vector<vector<pair<int, int> > > v;
bool check[1001];
typedef struct { int node; int val; }edge;
bool operator<(edge a, edge b) { return a.val > b.val; } //√÷º“»¸

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	priority_queue <edge> h;

	cin >> n >> m;
	v.resize(n + 1);

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}

	check[1] = 1;
	for (int i = 0; i < v[1].size(); i++)
		h.push({ v[1][i].first, v[1][i].second });

	int path = 1; int sum = 0;
	while (path <= n - 1) {

		if (check[h.top().node]) {
			h.pop();
			continue;
		}

		int idx = h.top().node;
		sum += h.top().val;
		path++;
		h.pop();
		check[idx] = 1;

		for (int i = 0; i < v[idx].size(); i++) {

			if (check[v[idx][i].first])
				continue;

			else
				h.push({ v[idx][i].first, v[idx][i].second });
		}
	}
	cout << sum;
	return 0;
}