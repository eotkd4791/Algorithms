//////////////////////////////
/*
        BOJ2150 SCC
                            */
//////////////////////////////

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define INF 10005
using namespace std;

int V, E;
vector<vector<int> > adj;
stack<int> discoverStack;
int discoverTime[INF];
int finishTime[INF];
int time;
int scc[INF];
int low[INF];
int check[INF];
bool checkp[INF];
int K = 1;

void DFS(int v) {
	discoverStack.push(v);
	check[v] = 1;
	discoverTime[v] = ++time;
	low[v] = discoverTime[v];

	int sz = adj[v].size();
	for (int i = 0; i < sz; i++) {
		int w = adj[v][i];
		if (check[w] == 0) {//white
			DFS(w);
			low[v] = min(low[v],low[w]);
		}

		if (check[w] == 1) //gray
			low[v] = min(low[v], discoverTime[w]);
		
		if (check[w] == 2) {//black
			if (discoverTime[v] < discoverTime[w]) { //forward edge
				continue;
			}

			else if(discoverTime[v]>finishTime[w]) {//cross edge
				if (scc[w] == 0) {//scc로 묶이지 않았다면
					low[v] = min(low[v], low[w]);
				}
				else //이미 묶였다면 무시
					continue;
			}
		}
	}

	check[v] = 2;
	finishTime[v] = ++time;
	if (low[v] == discoverTime[v]) {
		while (1) {
			int idx = discoverStack.top();
			scc[idx] = K;
			discoverStack.pop();
			if (idx == v) {
				K++;
				break;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cout.tie(0);

	cin >> V >> E;
	adj.resize(V + 1);

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) 
		if (check[i] == 0)
			DFS(i);

	cout << K - 1 << "\n";
	for (int i = 1; i <= V; i++) {
		if (!checkp[i]) {
			checkp[i] = 1;
			cout << i << " ";
			for (int j = i + 1; j <= V; j++) {
				if (scc[i] == scc[j]) {
					checkp[j] = 1;
					cout << j << " ";
				}
			}
			cout << "-1" << "\n";
		}
	}
	return 0;
}