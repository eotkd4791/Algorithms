nclude <iostream>
using namespace std;

int r,c,ans;
char field[22][22];
int dx[] ={0,0,-1,1}, dy[] = {1,-1,0,0};

inline bool OOB(int xx, int yy) {
    return 0 <= xx && xx < r && 0 <= yy && yy < c;
}

void dfs(int x, int y, int bit, int cnt) {
    ans = ans < cnt ? cnt : ans;
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        int idx= field[nx][ny]-'A';
        if(OOB(nx,ny) && !(bit&(1<<idx)))
            dfs(nx,ny,(bit|(1<<idx)),cnt+1);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> r >> c;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            cin >> field[i][j];

    int bit=0;
    bit |= 1<<(field[0][0]-'A');
    dfs(0,0,bit,1);
    cout << ans << '\n';
    return 0;
}
