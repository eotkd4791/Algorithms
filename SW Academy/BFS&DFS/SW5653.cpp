#include <bits/stdc++.h>
using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int field[700][700];
int T, n, m, k;

typedef struct { int x; int y; int age; } node;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for (int t = 1; t <= T; t++) {
        queue<node> q[11];

        cin >> n >> m >> k;

        for (int i = 350; i < n + 350; i++) {
            for (int j = 350; j < m + 350; j++) {
                cin >> field[i][j];
                if (field[i][j] > 0) q[field[i][j]].push({i, j, field[i][j] * 2});
            }
        }

        while (k--) {
            for (int i = 10; i >= 1; i--) {
                int qz = (int) q[i].size();

                while(qz--) {
                    node oq = q[i].front();
                    q[i].pop();

                    oq.age--;

                    if (field[oq.x][oq.y] > oq.age) { //활성 상태가 되면서 번
                        for (int dir = 0; dir < 4; dir++) {
                            int nx = oq.x + dx[dir];
                            int ny = oq.y + dy[dir];
                            if (field[nx][ny] == 0) {
                                field[nx][ny] = field[oq.x][oq.y];
                                q[i].push({ nx, ny, field[nx][ny] * 2 });
                            }
                        }
                    }
                    if (oq.age > 0) q[i].push({ oq.x, oq.y, oq.age });
                }
            }
        }
        int ans=0;
        for (int i = 1; i < 11; i++) ans += (int) q[i].size();
        cout << '#' << t << ' ' << ans << '\n';
        memset(field, 0, sizeof(field));
    }
    return 0;
}