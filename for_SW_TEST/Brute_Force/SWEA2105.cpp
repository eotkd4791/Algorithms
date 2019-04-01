//////////////////////////////////
/*
	SWEA2105 디저트 카페
				*/
//////////////////////////////////

/*
같은 방식으로 BFS로 풀었으나
check배열을 어디서 초기화할지 몰라서
재귀를 이용한 DFS방식으로 풀었다.
ios::sync_with_stdio(0);
cin.tie(0);
이 코드를 안 쓰니 답이 틀리게 나왔다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int T, N;
int field[22][22];
//bool checkp[22][22];
bool checkd[101]; //지나온 디저트 카페번호 표시
int dx[4] = { 1,1,-1,-1 };//우하, 좌하, 좌상, 우상
int dy[4] = { 1,-1,-1,1 };

//dir[0](1,1)우하 [1](1,-1)좌하  [2](-1,-1)좌상 [3](-1,1)우상 시계방향으로 세팅해놨음.
//반시계나 시계나 똑같음
//우하0 -> 우하0,좌하1    좌하1->좌하1,좌상2  좌상2->좌상2,우상3   우상3->우상3,우하0
int sx, sy;
int dir;
int MAX;

bool OOB(int x, int y) {
	if (0 <= x && x < N && N > y && y >= 0)
		return true;
	return false;
}

void DFS(int x, int y, int dir, int cnt) {
	if (x == sx && y == sy && cnt>1) {
		if (MAX < cnt) MAX = cnt;
		return;
	}
	for (int n = 0; n < 2; n++) {
		int nx = x + dx[dir + n];//n이 0일때는 원래 있던 방향, 1일때는 시계방향으로 한번 돌린거.
		int ny = y + dy[dir + n];
		if (OOB(nx, ny) && !checkd[field[nx][ny]]) {
			checkd[field[nx][ny]] = 1;
			DFS(nx, ny, dir + n, cnt + 1);
			checkd[field[nx][ny]] = 0;
		}//재귀를 이용하고 다시 돌아올때 check값들을 초기화해준다.
		else if (nx == sx && ny == sy) DFS(nx, ny, dir + n, cnt + 1);
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> field[i][j];
			}
		}
		MAX = -1;
		memset(checkd, 0, sizeof(checkd));

		for (int i = 0; i < N - 1; i++) {
			for (int j = 1; j < N - 1; j++) {
				sx = i; sy = j;
				checkd[field[i][j]] = 1;
				DFS(i, j, 0, 0);
				checkd[field[i][j]] = 0;
			}
		}
		cout << '#' << t << ' ' << MAX << '\n';
	}
	return 0;
}
