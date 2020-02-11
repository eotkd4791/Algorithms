#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > adj;
vector<int> ans;

int V, E;
int order[10001];
int low[10001];
int time = 1;

int dfs(int node, bool isRoot) {
	order[node] = time++;
	
	int ret = order[node];
	int child = 0;

	for (int i = 0; i < (int) adj[node].size(); i++) {
		int next = adj[node][i];
		if (order[next] == 0) {
			child++;
			int newNode = dfs(next, 0);
			if (!isRoot && newNode >= order[node]) 
				ans.push_back(node);
			ret = min(ret, newNode);
		}
		else {
			ret = min(ret, order[next]);
		}
	}
	if (isRoot && child > 1) 
		ans.push_back(node);
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> V >> E;
	adj.resize(V + 1);

	int a, b;
	for (int i = 0; i < E; i++){
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (order[i] > 0)  continue;
		dfs(i,1);
	}
	
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
	return 0;
}