#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
char field[303][303];
bool check[303][303];
queue<pair<int,int> > q;
int T,n;

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && n > yy && yy >= 0; }

void bfs(int x, int y) {
    check[x][y] = true;
    q.push(make_pair(x,y));

    while(!q.empty()) {
        pair<int,int> oq = q.front();
        q.pop();

        for(int dir=0; dir<8; dir++) {
            int nx = oq.first + dx[dir];
            int ny = oq.second + dy[dir];

            if(OOB(nx,ny) && !check[nx][ny] && field[nx][ny] !='*') {
                check[nx][ny] = true;
                int around = 0;
                for(int ddir=0; ddir<8; ddir++) {
                    int nnx = nx + dx[ddir];
                    int nny = ny + dy[ddir];
                    if(OOB(nnx,nny) && field[nnx][nny] == '*') around++;
                }
                if(around==0) q.push(make_pair(nx,ny));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> n;

        int cnt=0;
        memset(check,false, sizeof(check));
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin >> field[i][j];

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(field[i][j]=='.') {
                    int around = 0;
                    for(int dir=0; dir<8; dir++) {
                        int nx = i + dx[dir]; int ny = j + dy[dir];
                        if(OOB(nx, ny) && field[nx][ny] =='*') around++;
                    }
                    if(around == 0 && !check[i][j]) {
                        bfs(i,j);
                        cnt++;
                    }
                }
            }
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(!check[i][j] && field[i][j] != '*') cnt++;

        cout << '#' << t << ' ' << cnt << '\n';
    }
    return 0;
}