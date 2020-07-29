#include <iostream>
using namespace std;

int r,c,ans;
bool check[26];
char field[22][22];
int dx[] ={0,0,-1,1}, dy[] = {1,-1,0,0};

void dfs(int x, int y, int cnt) {
    ans = ans < cnt ? cnt : ans;
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if('A' <= field[nx][ny] && field[nx][ny] <= 'Z' && !check[field[nx][ny]-'A']) {
            check[field[nx][ny]-'A'] = true;
            dfs(nx,ny,cnt+1);
            check[field[nx][ny]-'A'] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> field[i][j];

    check[field[0][0]-'A'] = true;
    dfs(0,0,1);
    cout << ans << '\n';
    return 0;
}
