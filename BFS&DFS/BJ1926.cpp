/*BOJ 1926 그림
BFS를 이용한 Flood fill문제
queue에서 pop이 될 때마다 sum을 더하고 MAX값을 갱신했다.
queue초기화에 신경썼는데 사실상 while문을
탈출하려면 queue가 비어있어야 하니까...
또 field에서 0인 부분을 들어가지 않기 위해서 조건을 따로 추가했다.*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int N, M;
int field[510][510];
int cnt;
int check[510][510];
int sum, MAX;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void BFS(int x, int y) {
	queue <pair<int, int>> q = {};
	check[x][y] = 1;
	q.push({ x,y });
	while (q.empty() == 0) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sum++;
		for (int n = 0; n < 4; n++) {
			int rx = xnow + dr[n];
			int cy = ynow + dc[n];
			if (rx >= 0 && cy >= 0 && rx < N && cy < M && check[rx][cy] == 0 && field[rx][cy] != 0) {
				check[rx][cy] = 1;
				q.push({ rx,cy });
			}
		}
	}
	MAX = max(MAX, sum);
	sum = 0;
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n%d\n", cnt, MAX);
	return 0;
}