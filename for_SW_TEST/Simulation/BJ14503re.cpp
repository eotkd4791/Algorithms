#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
#define endl '\n'
using namespace std;
typedef struct { int x; int y; int d; int a; } cl;

int N, M, cnt;
bool field[55][55];
int check[55][55];
queue<cl> q;
int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

int bfs() {
	int ret = 0;

	while(!q.empty()) {
		cl cur = q.front();
		ret = cur.a;
		q.pop();
		

		int nd = cur.d; bool flag = false;
		for (int dir = 0; dir < 4; dir++) {
			if (nd == 0) 
				nd = 3;
			else 
				nd -= 1;

			int next_x = cur.x + dx[nd]; 
			int next_y = cur.y + dy[nd];
			int next_d = nd;
			
			if (field[next_x][next_y] == 1 || check[next_x][next_y]) {
				if (dir == 3) {
					int bd = (cur.d + 2) % 4;
					int back_x = cur.x + dx[bd];
					int back_y = cur.y + dy[bd];

					if (field[back_x][back_y] == 1) 
						return ret;
		
					else {
						cl back = { back_x,back_y,cur.d,cur.a };
						q.push(back);
						break;
					}
				}
				else
					continue;
			}
			check[next_x][next_y] = true;
			cl next = { next_x, next_y, nd, cur.a + 1 };
			q.push(next);
			break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cl st;
	cin >> N >> M;
	cin >> st.x >> st.y >> st.d;
	st = { st.x, st.y, st.d,1 };
	check[st.x][st.y] = true;
	q.push(st);

	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> field[i][j];

	int ret = bfs();
	cout << ret << endl;
	return 0;
}