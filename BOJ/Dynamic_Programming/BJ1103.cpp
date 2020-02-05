#include <iostream>
#include <algorithm>
using namespace std;

int N,M,MAX,cnt;
int field[55][55], dist[55][55];
bool check[55][55];
const int dx[] = {0,0,-1,1};
const int dy[] = {-1,1,0,0};

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < N && M > yy && yy >= 0; }

int dp(int x, int y) {
    if(field[x][y] == 0 || !OOB(x,y)) return 0;
    if(check[x][y]) {
        cout << "-1" << '\n';
        exit(0);
    }
    if(dist[x][y]>0) return dist[x][y];
    
    check[x][y]=true;
    for(int i=0; i<4; i++) {
        int nx = x + dx[i] * field[x][y];
        int ny = y + dy[i] * field[x][y];
        dist[x][y] = max(dist[x][y], dp(nx,ny)+1);
    }
    check[x][y]=false;
    return dist[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    char a;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a;
            if(a != 'H') field[i][j] = a - '0';
            else field[i][j] = 0;
        }
    }
    cout << dp(0,0) << '\n';
    return 0;
}
