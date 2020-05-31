nclude <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct{
    int x;
    int y;
    int dist;
}node;
int field[55][55], N, M, R, C, L, ans;
bool check[55][55];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool pipe[7][4] = {
    { true, true, true, true },
    { true, false, true, false },
    { false, true, false, true },
    { true, true, false, false },
    { false, true, true, false },
    { false, false, true, true },
    { true, false, false, true }
};


inline bool OOB(int x, int y) { return 0 <= x && x < N && M > y && y >= 0; }

void bfs(int stx, int sty) {
    queue<node> q;
    q.push({stx, sty, 1});
    check[stx][sty] = true;
    
    while(!q.empty()) {
        node oq = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++) {
            int nx = oq.x + dx[dir];
            int ny = oq.y + dy[dir];
            
            if(!OOB(nx, ny) || check[nx][ny] || !pipe[field[oq.x][oq.y]][dir] || field[nx][ny] < 0) continue;
            if(pipe[field[oq.x][oq.y]][dir] != pipe[field[nx][ny]][(dir + 2) % 4]) continue;
            if(oq.dist+1>L) continue;
            check[nx][ny] = true;
            q.push({nx, ny, oq.dist + 1});
        }
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            if(check[i][j]) ans++;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    for(int t = 1; t <= T; t++) {
        ans=0;
        memset(check, false, sizeof(check));
        
        cin >> N >> M >> R >> C >> L;
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                cin >> field[i][j];
                field[i][j]--;
            }
        }
            
        bfs(R, C);
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}
