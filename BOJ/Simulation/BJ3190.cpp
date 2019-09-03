#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int N, K, M;
int field[101][101];//»ç°ú 1
deque<pair<int, int> > D;
char dir[10001];
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

	cin >> N;
	cin >> K;
	int a, b;
	for (int k = 0; k < K; k++) {
		cin >> a >> b;
		field[a][b] = 1;
	}
	cin >> M; 
	int x; char d;
	for (int l = 0; l < M; l++) {
		cin >> x >> d;
		dir[x] = d;
	}

	D.push_back(make_pair(1, 1));
	int time = 0; int idir = 1;
	int nDx = D.front().first;
	int nDy = D.front().second;

	while (1) {
		time++;
		nDx += dx[idir];
		nDy += dy[idir];

		if (1 > nDx || nDx > N || N < nDy || nDy < 1)
			break;

	
		for (int i = 0; i < D.size(); i++) 
			if (nDx == D[i].first && nDy == D[i].second) {
				cout << time;
				return 0;
			}
		
		D.push_front(make_pair(nDx, nDy));

		if (field[nDx][nDy] == 1) 
			field[nDx][nDy] = 0;
		
		else if (field[nDx][nDy] == 0) 
			D.pop_back();
		
		if (dir[time] != NULL)
			idir = turn(idir,dir[time]);
	}
	cout << time;
	return 0;
}