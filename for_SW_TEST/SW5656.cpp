#include <iostream>
#include <cstring>

using namespace std;

int n, w, h, res;
int field[20][20];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < h && 0 <= yy && yy < w; }

void sorting() {
    for (int i = 0; i < w; i++) {
        for (int j = h - 1; j >= 1; j--) {
            for (int k = j - 1; k >= 0; k--) {
                if (field[j][i] != 0) break;
                if (field[k][i] != 0) {
                    field[j][i] = field[k][i];
                    field[k][i] = 0;
                    break;
                }
            }
        }
    }
}

void dfs(int x, int y) {
    int dist = field[x][y];
    if (dist == 0) return;
    field[x][y] = 0;
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 0; i < dist; i++) {
            int nx = x + dx[dir] * i;
            int ny = y + dy[dir] * i;
            if (!OOB(nx, ny) || field[nx][ny] == 0) continue;
            dfs(nx, ny);
        }
    }
}

void recur(int cnt) {
    int tmp[20][20] = {};
    if (cnt == n) {
        int bricks = 0;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                if (field[i][j] > 0) bricks++;
        res = res > bricks ? bricks : res;
        return;
    }
    for (int i = 0; i < w; i++) {
        memcpy(tmp, field, sizeof(field));
        int x = 0, y = i;
        while (field[x][y] == 0 && x < h) x++;
        dfs(x, y);
        sorting();
        recur(cnt + 1);
        memcpy(field, tmp, sizeof(field));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        res = 987654321;

        cin >> n >> w >> h;

        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> field[i][j];
        recur(0);

        cout << '#' << t << ' ' << res << '\n';
    }
    return 0;
}
