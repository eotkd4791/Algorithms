#include <iostream>
using namespace std;

int field[10][10], n, k, mh, lp;
const int dx[4]  = {0,0,-1,1};
const int dy[4] = {1,-1,0,0};
bool check[10][10];

inline bool OOB(int xx, int yy) {
    return 0 <= xx && xx < n && n > yy && yy >= 0;
}

void dfs(int x, int y,  bool isDigged, int cnt) {
    lp = lp < cnt ? cnt : lp;
    check[x][y] = true;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
        if(!OOB(nx,ny) || check[nx][ny]) continue;
        
        if(field[nx][ny] < field[x][y]) dfs(nx,ny, isDigged, cnt + 1);
        
        else {
            if(field[nx][ny] - k < field[x][y] && !isDigged) {
                int tmp = field[nx][ny];
                field[nx][ny] = field[x][y] - 1;
                dfs(nx,ny, true, cnt + 1);
                field[nx][ny] = tmp;
            }
        }
    }
    check[x][y] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T;
    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> n >> k;
            
        mh = lp = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                cin >> field[i][j];
                mh = mh < field[i][j] ? field[i][j] : mh;
            }
        }
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                if(field[i][j] == mh)
                    dfs(i, j, false, 1);
                
        cout << '#' << t << ' ' << lp << '\n';
    }
    return 0;
}
