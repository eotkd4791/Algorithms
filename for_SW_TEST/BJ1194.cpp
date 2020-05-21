#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

typedef struct { int x; int y; int dist; int key; } node;
queue<node> q;
int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};
int N, M, ans = INF;
char field[55][55];
bool check[55][55][1<<6];

inline bool OOB(int x, int y) { return 0 <= x && x < N && M > y && y >= 0; }

void bfs() {
    while(!q.empty()) {
        node oq = q.front();
        q.pop();
       
        for(int dir = 0; dir < 4; dir++) {
            int nx = oq.x + dx[dir];
            int ny = oq.y + dy[dir];
            int nd = oq.dist + 1;
            int newKey = oq.key;
            
            if(!OOB(nx, ny) || field[nx][ny] == '#' || check[nx][ny][newKey]) continue;
            check[nx][ny][newKey] = true;
            
            if('A' <= field[nx][ny] && field[nx][ny] <= 'F') {
                int idx = field[nx][ny] - 'A';
                if(newKey & (1 << idx)) { // 키가 있다.
                    q.push({ nx, ny, nd, newKey });
                }
            }
            else {
                if(field[nx][ny] == '.') { //빈칸
                    q.push({ nx, ny, nd, newKey });
                }
                else if(field[nx][ny] == '1') { // 출구
                    ans = ans > nd ? nd : ans;
                    return;
                }
                else { //열쇠 줍줍
                    int idx = field[nx][ny] - 'a';
                    newKey|=(1<<idx);
                    q.push({ nx, ny, nd, newKey });
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> field[i][j];
            if(field[i][j] == '0') {
                q.push({ i, j, 0, 0 });
                field[i][j] = '.';
                check[i][j][0] = true;
            }
        }
    }
    bfs();
    cout << (ans != INF ? ans : -1) << '\n';
    return 0;
}
