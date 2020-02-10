#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int N,M;
vector<pair<int, pair<int, int> > > v;
vector<vector<int> > adj;
bool check[1010];
int parent[1010];
int height[1010];

void init() {
	for (int i = 1; i <= N; i++) {
		height[i] = 1;
		parent[i] = i;
	}
}
int find(int v) {
	if (parent[v] == v) return v;
	return parent[v] = find(parent[v]);
}
void merge(int u, int v) {
	int ru = find(u);
	int rv = find(v);
	
	if (height[ru] > height[rv]) {
		parent[rv] = ru;
	}
	else if(height[ru] < height[rv]) {
		parent[ru] = rv;
	}
	else {
		parent[ru] = rv;
		height[rv] = ++height[ru];
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	adj.resize(N + 1);

	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back(make_pair(c, make_pair(a, b)));
	}

	sort(v.begin(), v.end());
	init();
    
	int vz = (int) v.size();
	int weightSum = 0;
	
	for(int i = 0; i < vz; i++) {
		if (find(v[i].second.first) == find(v[i].second.second))
			continue;
		
		merge(v[i].second.first, v[i].second.second);
        weightSum += v[i].first;
        
		adj[v[i].second.first].push_back(v[i].second.second);
		adj[v[i].second.second].push_back(v[i].second.first);
	}
	cout << weightSum << '\n';
	return 0;
}