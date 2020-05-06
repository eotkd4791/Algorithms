#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct { int x; int y; int pipe; int cnt; } node;
int field[55][55], n, m, r, c, l, T, ans;
bool check[55][55];
queue<node> q;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && m > yy && yy >= 0; }


void bfs(int x, int y, int pipe) {
    q.push({x, y, pipe, 1});
    check[x][y] = true;
    
    while(!q.empty()) {
        node oq = q.front();
        q.pop();
        
        if(oq.cnt+1 > l) break;
        for(int dir=0; dir<4; dir++) {
            int nx = oq.x + dx[dir];
            int ny = oq.y + dy[dir];
            
            if(!OOB(nx,ny) || field[nx][ny] == 0 || check[nx][ny]) continue;
            
            switch (oq.pipe) {
                case 1:
                    if(dir == 0) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 5 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 1) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 7 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 2) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 4 || field[nx][ny] == 7) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else {
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 5 || field[nx][ny] == 4) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                case 2:
                    if(dir == 0) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 5 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 2) { //2
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 4 || field[nx][ny] == 7) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                case 3:
                    if(dir == 1) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 7 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 3) { //3
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 5 || field[nx][ny] == 4) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                case 4:
                    if(dir == 0) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 5 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 1) { //1
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 7 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                case 5:
                    if(dir == 1) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 7 || field[nx][ny] == 6) {
                           check[nx][ny] = true;
                           q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 2) { // 2
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 4 || field[nx][ny] == 7) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                case 6:
                    if(dir == 2) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 4 || field[nx][ny] == 7) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir == 3) { //3
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 5 || field[nx][ny] == 4) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
                default:
                    if(dir == 0) {
                        if(field[nx][ny] == 1 || field[nx][ny] == 2 || field[nx][ny] == 5 || field[nx][ny] == 6) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    else if(dir==3) { // 3
                        if(field[nx][ny] == 1 || field[nx][ny] == 3 || field[nx][ny] == 5 || field[nx][ny] == 4) {
                            check[nx][ny] = true;
                            q.push({nx,ny,field[nx][ny], oq.cnt + 1});
                        }
                    }
                    break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> n >> m >> r >> c >> l;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> field[i][j];
            
        bfs(r, c, field[r][c]);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(check[i][j]) ans++;
                
        cout << '#' << t << ' ' << ans << '\n';
        memset(check, false, sizeof(check));
        ans = 0;
        queue<node> tmp;
        swap(tmp, q);
    }
    return 0;
}

