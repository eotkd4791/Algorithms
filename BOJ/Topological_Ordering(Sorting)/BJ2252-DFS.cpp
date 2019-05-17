/////////////////////////////////////
/*
        BOJ2252 줄 세우기 (DFS)
                                   
/////////////////////////////////////

DFS로 위상정렬 구현
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
int ii;
int ans[32001];
int colour[32001];
bool flag;
vector<vector<int> > v(32001);
queue<int> q;

void DFS(int vv) {
	colour[vv] = 1;
	int sz = v[vv].size();
	for (int i = 0; i < sz; i++) {
		int ww = v[vv][i];
		if (colour[ww] == 0) DFS(ww);
	}
	ans[ii++] = vv;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		v[a].push_back(b);
	}

	for (int i = 1; i <= N; i++) 
		if (colour[i] == 0) DFS(i);
	
	
	for (int i = N-1; i >=0; i--)
		cout << ans[i] << ' ';
	return 0;
}