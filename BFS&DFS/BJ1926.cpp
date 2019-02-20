/*BOJ 1926 그림
BFS를 이용한 Flood fill문제
queue에서 pop이 될 때마다 sum을 더하고 MAX값을 갱신했다.
queue초기화에 신경썼는데 사실상 while문을
탈출하려면 queue가 비어있어야 하니까...
또 field에서 0인 부분을 들어가지 않기 위해서 조건을 따로 추가했다.*/
/*BOJ 1926 그림
BFS를 이용한 Flood fill문제
queue에서 pop이 될 때마다 sum을 더하고 MAX값을 갱신했다.
queue초기화에 신경썼는데 사실상 while문을
탈출하려면 queue가 비어있어야 하니까...
또 field에서 0인 부분을 들어가지 않기 위해서 조건을 따로 추가했다.*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n, m, field[501][501], check[501][501], cnt, sum, MAX;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void BFS(int x, int y) {
	queue<pair<int, int>> q = {};
	check[x][y] = 1;
	q.push({ x,y });
	while (q.empty() == 0) {
		int xnow = q.front().first;
		int ynow = q.front().second;
		q.pop();
		sum++;
		for (int k = 0; k < 4; k++) {
			int rx = xnow + dr[k];
			int cy = ynow + dc[k];
			if (rx >= 0 && cy >= 0 && rx < n && cy < m && check[rx][cy] == 0 && field[rx][cy] == 1) {
				check[rx][cy] = 1;
				q.push({ rx,cy });
			}
		}
	}
	MAX = max(MAX, sum);
	sum = 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &field[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == 0 && field[i][j] == 1) {
				BFS(i, j);
				cnt++;
			}
		}
	}
	printf("%d\n%d", cnt, MAX);
	return 0;
}