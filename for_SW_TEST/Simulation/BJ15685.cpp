///////////////////////////////
/*
      BOJ15685 드래곤 커브
                             */
///////////////////////////////


#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

int N;
int y, x, d, g;
int field[111][111];
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
vector<int> v;
int cnt;

bool OOB(int X, int Y) {
	if (0 <= X && X <= 100 && 100 >= Y && Y >= 0)
		return true;
	return false;
}
int rtt(int n) {
	int val = (n + 1) % 4;
	return val;
}

void footprint(int X, int Y, stack<int> &s, vector<int> &v) {
	field[X][Y]++;
	int vs = v.size();
	for (int i = 0; i < vs; i++) {
		int od = v[i];
		int nx = X + dx[od];
		int ny = Y + dy[od];
		if (OOB(nx,ny)) {
			field[nx][ny]++;
			X = nx;
			Y = ny;
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		stack<int> s = {};
		v.clear();
		scanf("%d%d%d%d", &y, &x, &d, &g);
		s.push(d);
		v.push_back(d);
		int sc = pow(2, g);
		
		while (sc!=v.size()) {
			int tmp = s.top();
			int num = rtt(tmp);
			v.push_back(num);
			s.pop();
			if (s.empty()) {
				for (int i = 0; i < v.size(); i++) {
					s.push(v[i]);
				}
			}
		}
		footprint(x,y,s,v);
	}
	
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (i + 1 <= 100 && j + 1 <= 100) {
				if (field[i][j] > 0 && field[i + 1][j] > 0 && field[i + 1][j + 1] > 0 && field[i][j + 1] > 0) {
					cnt++;
				}
			}
		}
	}
	printf("%d\n", cnt);
	return 0;
}
