#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, M;
int field[101][101];
bool check[101][101];
typedef struct { int idx; char dir; }node;
deque<pair<int, int> > D;
queue<node> q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int turn(int cdir,char ddir) {
	if (ddir == 'L') {
		if (cdir == 0)
			return 3;
		else
			return cdir - 1;
	}
	else {
		if (cdir == 3)
			return 0;
		else
			return cdir + 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	int a, b;
	while(K--) {
		cin >> a >> b;
		field[a][b] = 1;
	}

	cin >> M; 
	int x; char d;
	while(M--) {
		cin >> x >> d;
		q.push({ x,d });
	}

	D.push_back(make_pair(1, 1));
	int time = 0; int idir = 1;
	int nDx = D.front().first;
	int nDy = D.front().second;

	while (1) {
		time++;
		check[nDx][nDy] = 1;
		nDx += dx[idir];
		nDy += dy[idir];

		if (1 > nDx || nDx > N || N < nDy || nDy < 1)
			break;

		if (check[nDx][nDy])
			break;

		D.push_front(make_pair(nDx, nDy));
		if (field[nDx][nDy] == 1)
			field[nDx][nDy] = 0;

		else if (field[nDx][nDy] == 0) {
			check[D.back().first][D.back().second] = 0;
			D.pop_back();
		}
		
		if (q.front().idx == time) {
			idir = turn(idir, q.front().dir);
			q.pop();
		}
	}
	cout << time;
	return 0;
}