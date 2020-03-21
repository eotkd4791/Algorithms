#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int field[700][700];
int T, n, m, k, ans;

typedef struct { int x; int y; int time; } node;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        memset(field, 0, sizeof(field)); ans = 0;
        queue<node> q[11];

        cin >> n >> m >> k;

        for (int i = 350; i < n + 350; i++) {
            for (int j = 350; j < m + 350; j++) {
                cin >> field[i][j];
                if (field[i][j]) q[field[i][j]].push({i, j, field[i][j] * 2});
            }
        }

        while (k--) {
            for (int i = 10; i >= 1; i--) {
                int qz = (int) q[i].size();

                while(qz--) {
                    node oq = q[i].front();
                    int x = oq.x;
                    int y = oq.y;
                    int time = oq.time;
                    q[i].pop();

                    time--;

                    if (field[x][y] > time) { 
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = x + dx[dir];
                            int ny = y + dy[dir];
                            if (field[nx][ny] == 0) {
                                field[nx][ny] = field[x][y];
                                q[i].push({ nx, ny, field[nx][ny] * 2 });
                            }
                        }
                    }
                    if (time > 0) q[i].push({ x, y, time });
                }
            }
        }
        for (int i = 1; i < 11; i++) ans += (int) q[i].size();
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}