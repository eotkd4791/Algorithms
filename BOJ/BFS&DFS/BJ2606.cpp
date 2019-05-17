//////////////////////////////////////
/*
          BOJ2606 바이러스
                                    */
//////////////////////////////////////
#include <iostream>
#include <vector>
using namespace std;

int V, E;
int cnt;
bool check[101];
vector<vector<int> > v(101);

void DFS(int vv) {
	check[vv] = 1;
	cnt++;
	int ww = v[vv].size();
	for (int i = 0; i < ww; i++) {
		int idx = v[vv][i];
		if (!check[idx]) {
			check[idx] = 1;
			DFS(idx);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(1);
	cout << cnt-1;
	return 0;
}