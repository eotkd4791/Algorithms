/*적록색약-방향키 코드(flood fill)을 이용하여 풀었다. 
색깔이 같은 영역끼리만 이동해야하기 때문에 
조건에 " field[rx][cy] == field[x][y] "을
추가하여 풀었다.*/
#include <iostream>
#include <cstring>
using namespace std;
int N;
char field[101][101];
int cnt;
int check[101][101];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { -1,1,0,0 };

void DFS(int x, int y) {
	if (check[x][y] != 0) return;
	check[x][y] = 1;
	for (int n = 0; n < 4; n++) {
		int rx = x + dr[n];
		int cy = y + dc[n];
		if (rx >= 0 && cy >= 0 && rx < N && cy < N && field[rx][cy] == field[x][y] && check[rx][cy] == 0) {
			DFS(rx, cy);
		}
	} 
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%s", &field[i]);
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (check[i][j]==0) cnt++;
			DFS(i, j);
		}
	}
	printf("%d ",cnt);
	cnt = 0;
	memset(check, 0, sizeof(check));
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++)
			if (field[i][j] == 'G') field[i][j] = 'R';
	}
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			if (check[i][j]==0) cnt++;
			DFS(i, j);
		}
	}
	printf("%d\n", cnt);
	return 0;
}
