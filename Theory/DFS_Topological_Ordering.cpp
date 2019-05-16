////////////////////////////////////////
/*
   DFS Topological Ordering(Sorting)

////////////////////////////////////////

## DFS를 이용한 위상정렬 구현 ##

check배열에 White(0), Gray(1), Black(2)
세 가지 각각의 특성을 고려하여 cycle유무를
검사하고, 사이클이 존재하면 '위상정렬 실패'
라는 문구를 출력하고 사이클이 존재하지 않으면
위상정렬된 노드의 순서를 출력한다.

자료구조 연결리스트를 공부해서 벡터를 리스트로
구현하는 연습을 해야겠다.
*/


#include <iostream>
#include <vector>
using namespace std;

int V, E;
int time;
int check[10];
int discover[10];
int finish[10];
int arr[10];
int ii;
bool cycle_exist;
vector<vector<int> > adj(10);

void DFS(int v) {
	check[v] = 1;
	discover[v] = ++time;

	int adjacent = adj[v].size();
	for (int j = 0; j < adjacent; j++) {
		int w = adj[v][j];
		if (check[w] == 0) { //white
			check[w] = 1;
			DFS(w);
		}
		if (check[w] == 1) { //gray
			cycle_exist = 1;
			return;
		}
		if (check[w] == 2) { //black
			continue;
		}
		
	}
	finish[v] = ++time;
	check[v] = 2;
	arr[ii++] = v;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 1; i <= V; i++) {
		if (check[i] == 0) {
			DFS(i);
		}
	}

	if (cycle_exist) {
		cout << "위상정렬 실패\n";
	}
	else {
		for (int i = V - 1; i >= 0; i--) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}