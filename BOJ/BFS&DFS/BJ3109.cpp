#include <iostream>
#include <algorithm>
using namespace std;

int R,C,cnt;
bool flag;
char field[10001][501];
const int dx[] = {-1, 0, 1};
const int dy[] = {1, 1, 1};
bool check[10001][501];
   
inline bool OOB(int xx, int yy) { return (0 <= xx && xx < R && C > yy && yy >= 0); }

void dfs(int x, int y) {
    if(y == C-1) {
        cnt++;
        flag= true;
        return;
    }
    
    for(int dir=0; dir<3; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx,ny) && !check[nx][ny] && field[nx][ny] != 'x') {
            check[nx][ny]=true;
            dfs(nx,ny);
            if(flag) break;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> R >> C;
    for(int i=0; i<R; i++)
        for(int j=0; j<C; j++)
            cin >> field[i][j];
    
    for(int i=0; i<R; i++) {
        if(!check[i][0]){
            check[i][0]=true;
            dfs(i,0);
            flag = false;
        }
    }
    cout << cnt << '\n';
    return 0;
}
