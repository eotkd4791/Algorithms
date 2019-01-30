//-DFS & BFS 구현하는 문제 BJ1260-
//정점의 갯수N, 간선의 갯수M, 탐색을 시작하는 점V.
//adj[1]→2→3→4
//adj[2]→1→4
//adj[3]→1→4
//adj[4]→1→2→3
//
//Vector함수를 이용해서 그래프를 만든다. <main함수>

#include <iostream>
#include <algorithm>									//sort
#include <cstring>										//visited배열 초기화 memset
#include <queue>										//BFS를 구현하기 위해 필요한 queue
#include <vector>										//줄 긋기
using namespace std;

int N, M, V, a, b;
int visited[1005];
queue <int> q;				
vector <vector <int>> adj(1005);

void DFS (int now) {											//DFS 깊이우선탐색 함수
	visited[now] = 1;											//visited배열을 dp에서 check배열처럼 이용한다. 이미 방문했으면 1 아니면 0.
	printf("%d ", now);
	for (int i = 0; i <adj[now].size(); i++) {				//adj벡터배열의 크기만큼 for문을 돌린다.
		int next = adj[now][i];
		if (visited[next] == 0) DFS(next);					//방문하지 않았다면 next를 매개변수삼아 함수를 돌린다.
	}
}

void BFS(int start) {												//BFS 너비우선탐색 함수
	visited[start] = 1;										
	q.push(start);													//q.push함수를 이용해 매개변수로 들어온 값을 Queue에 저장한다.
	while (q.empty() == 0) {									//q.empty함수는 Queue에 아무것도 없다면 1, 내용이 있다면 0을 반환한다.
		int now = q.front();										//Queue에 아무것도 없을때까지 반복문을 실행한다.
		q.pop();														//q.pop함수를 이용해서 Queue의 가장 앞자리의 값(새롭게 기준이 되는 정점)을 빼준다.
		printf("%d ", now);										
		for (int i = 0; i <adj[now].size(); i++) {
			int next = adj[now][i];
			if (visited[next] == 0) {
				visited[next] = 1;
				q.push(next);										//Queue에는 다음번에 탐색할 정점들이 들어가 있고, 모든 탐색이 끝나면 Queue가 비워지고,
			}															//while문을 빠져나오게 된다.
		}
	}
}

int main() {
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);													//정점의 좌표 a,b를 push_back함수를 이용하여 연결해준다.
		adj[b].push_back(a);													
	}
	for (int i = 1; i <= N; i++) {
		sort(adj[i].begin(), adj[i].end());								//값이 차례대로 입력되지 않거나 방문순서가 꼬이는 것을 방지하기위해 정렬한다.
	}																				//adj에 들어있는 내용을 인덱스마다 정렬하기 위해서 for문안에서 구현한다.
	DFS(V);
	printf("\n");
	memset(visited, 0, sizeof(visited));								//BFS들어가기 전에 visited배열 초기화
	BFS(V);
	printf("\n");
	return 0;
}