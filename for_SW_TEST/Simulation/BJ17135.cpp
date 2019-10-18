#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#include <cstring>
#include <vector>
#define endl '\n'
using namespace std;

int N, M, D, MAX,num;
int field[20][20];
int tmp[20][20];
bool check[20][20];
bool ispicked[20];
int dx[] = { 0,-1,0 };
int dy[] = { -1,0,1 };
typedef struct { int x; int y; int d; }node;
vector<int> v;

inline bool OOB(int x, int y) {
	if (0 <= x && x < N && M > y && y >= 0)
		return true;
	return false;
}

void moving() {
	for (int i = N-1; i >=1; i--) 
		for (int j = 0; j < M; j++) 
			field[i][j] = field[i - 1][j];
	for (int j = 0; j < M; j++)
		field[0][j] = 0;
}

void bfs() {
	num = 0;
	int idx = 0;
	vector<pair<int, int> > enemy;
	while (idx++ < N) {
		for (int i = 0; i < 3; i++) {
			memset(check, 0, sizeof(check));
			queue<node> q;

			q.push({ N, v.at(i), 0 });
			while (!q.empty()) {
				node cur = q.front();
				q.pop();

				bool flag = 0;
				for (int dir = 0; dir < 3; ++dir) {
					node next = { cur.x + dx[dir], cur.y + dy[dir], cur.d + 1 };

					if (OOB(next.x, next.y) && next.d <= D) {
						if (field[next.x][next.y] == 1) {
							enemy.push_back(make_pair(next.x, next.y));
							flag = 1;
							break;
						}
						check[next.x][next.y] = 1;
						q.push(next);
					}
				}
				if (flag)
					break;
			}
		}
		enemy.erase(unique(enemy.begin(), enemy.end()), enemy.end());
		for (int i = 0; i < enemy.size(); i++) {
			field[enemy.at(i).first][enemy.at(i).second] = 0;
			num++;
		}
		enemy.clear();
		moving();
	}
}

void dfs(int idx, int cnt) {
	if (cnt == 3) {
		bfs();
		MAX = max(MAX,num);
		memcpy(field, tmp, sizeof(tmp));
		return;
	}
	for (int i = idx; i < M; i++) {
		if (!ispicked[i]) {
			ispicked[i] = 1;
			v.push_back(i);
			dfs(i + 1, cnt + 1);
			v.pop_back();
			ispicked[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M >> D;
	
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> field[i][j];
			
	memcpy(tmp, field, sizeof(field));
	dfs(0, 0);
	cout << MAX << endl;
	return 0;
}