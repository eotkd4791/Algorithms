////////////////////////////////////////
/*
   BFS Topological Ordering(Sorting)

////////////////////////////////////////

## BFS를 이용한 위상정렬 구현 ##

Indegree의 갯수가 0인 노드를 큐에 푸쉬하고
BFS함수를 호출한다.
큐에 푸쉬되어 있는 노드와 인접한 노드들의
Indegree갯수를 감소시키면서 Indegree갯수가 
0이 되는 노드들을 다시 푸쉬하는 방식으로 
진행한다. 사이클이 있다면 Indegree갯수가 0이
아닌 노드가 적어도 2개는 존재하므로
큐로 더이상의 푸쉬가 발생하지 않아서 
BFS함수를 벗어난다.
pop되는 노드들을 순서대로 저장해놨던 배열의 
원소의 갯수가 노드의 갯수와 같지 않다면
사이클이 존재하여 위상정렬이 불가능한 경우이므로
"위상정렬 실패"라는 문구를 출력한다.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int V, E;
int check[10];
int ind[10];
int arr[10];
int ii;
queue<int> q;
vector<vector<int> > v(100);

void BFS() {
	while (!q.empty()) {
		int oq = q.front();

		int sz = v[oq].size(); 
			for (int i = 0; i < sz; i++) {
				int idx = v[oq][i];
				ind[idx]--;
				if (ind[idx] == 0)
					q.push(idx);
			}
		arr[ii++] = oq;
		q.pop();
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
		ind[b]++;
	}

	for (int i = 1; i <= V; i++)
		if (ind[i] == 0) q.push(i);
	BFS();

	if (arr[V - 1] == 0) cout << "위상정렬 실패" << "\n";
	else {
		for (int i = 0; i < V; i++) {
			cout << arr[i] << ' ';
		}
	}
	return 0;
}