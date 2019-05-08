///////////////////////////////////////
/*
		SWEA1861 정사각형 방

///////////////////////////////////////
1~n^2까지의 수가 배열에 저장되는데
예를 들어 1부터 5까지 연결되어 있어서
5까지 탐색을 끝내면 1~5사이의 숫자는 더이상
볼 필요가 없다.
(탐색해도 더 짧은 길이의 값이
나오기 때문에...)
1차원의 배열(arr)을 만들어서 입력과
동시에 arr배열을 채워 넣고,
재귀탐색으로 연결되어 있는 길이를 구하고,
탐색을 끝낸 마지막 값부터 다시 탐색하는 방식으로
구현했다.
최적화에 대해 고민해본 문제여서 재미있었다.
*/
#include <iostream>
using namespace std;

int n;
int field[1001][1001];

typedef struct {
	int X;
	int Y;
}node;
node arr[10000010];
int st=1, M;
int tmp;
const int dx[] = { 0,0,1,-1 };
const int dy[] = { 1,-1,0,0 };

bool OOB(int x, int y) {
	if (0 <= x && x < n && n > y && y >= 0)
		return true;
	return false;
}

void recur(int x, int y, int stt, int len) {
	for (int n = 0; n < 4; n++) {
		int nx = x + dx[n];
		int ny = y + dy[n];
		if (OOB(nx, ny)) 
			if (field[x][y] + 1 == field[nx][ny]) {
				recur(nx, ny, stt, len + 1);
				break;
			}
		if (n == 3) {
			if (len > M) {
				M = len;
				st = stt;
			}
			if (len == M) {
				if (st > stt) st = stt;
			}
			tmp = stt + len;
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> field[i][j];
				node point = { i,j };
				arr[field[i][j]] = point;
			}
		}
		int last = 1;
		while (last < n*n) {
			recur(arr[last].X, arr[last].Y, last,1);
			last = tmp;
		}
		cout << '#' << t << ' ' << st << ' ' << M << '\n';
		st = 1;
		M = 0;
		
	}
	return 0;
}