#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int R, C, ax,ay;
char field[26][26], ap;
bool check[26][26];
int dx[] = {-1, 0, 1, 0}, dy[] = {0,1,0,-1};
queue<pair<int, int> > q;
vector<pair<int, int> > v;
bool pipe[7][4] = {
    {false, true, true, false},
    {true, true, false, false},
    {true, false, false, true},
    {false, false, true, true},
    {true, false, true, false},
    {false, true, false, true},
    {true, true, true, true},
};
// | ㅡ +

inline bool OOB(int x, int y) { return 1 <= x && x <= R && C >= y && y >= 1; }

int getIdx(char ch) {
    if(ch=='1') return 0;
    if(ch=='2') return 1;
    if(ch=='3') return 2;
    if(ch=='4') return 3;
    if(ch=='|') return 4;
    if(ch=='-') return 5;
    else return 6;
}
char getPipe(int idx) {
    if(idx==0) return '1';
    if(idx==1) return '2';
    if(idx==2) return '3';
    if(idx==3) return '4';
    if(idx==4) return '|';
    if(idx==5) return '-';
    else return '+';
}

bool testPipe(int nx, int ny) {
    bool comp[4]={false, false, false, false};
    for(int ddir=0; ddir<4; ddir++) {
        int nnx = nx + dx[ddir];
        int nny = ny + dy[ddir];
        
        if(!OOB(nnx, nny) || field[nnx][nny]=='.' || field[nnx][nny] == 'M' || field[nnx][nny] =='Z') continue;
        int cIdx = getIdx(field[nnx][nny]);
        comp[ddir] = pipe[cIdx][(ddir + 2) % 4];
    }
    for(int i=0; i<7; i++) {
        for(int j=0; j<4; j++) {
            if(pipe[i][j]==comp[j]) {
                if(j == 3) {
                    ax = nx; ay = ny; ap = getPipe(i);
                    return true;
                }
            }
            else break;
        }
    }
    return false;
}

void bfs(int x, int y) {
    q.push(make_pair(x, y));
    check[x][y] = true;
    
    while(!q.empty()) {
        pair<int,int> oq = q.front();
        q.pop();
        
        int oIdx = getIdx(field[oq.first][oq.second]);
        
        for(int dir = 0; dir<4; dir++) {
            int nx = oq.first + dx[dir];
            int ny = oq.second + dy[dir];
            
            if(!OOB(nx,ny) || check[nx][ny] || !pipe[oIdx][dir]) continue;
            if(field[nx][ny] == '.') {
                bool flag = testPipe(nx, ny);
                if(flag) return;
            }
            int nIdx = getIdx(field[nx][ny]);
            if(pipe[oIdx][dir] != pipe[nIdx][(dir + 2) % 4]) continue;
            
            check[nx][ny] = true;
            if(field[nx][ny]!= 'M' && field[nx][ny] != 'Z') q.push(make_pair(nx,ny));
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> R >> C;
    
    pair<int,int> st;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin >> field[i][j];
            if(field[i][j]=='M') st = make_pair(i,j);
        }
    }
    for(int dir=0; dir<4; dir++) {
        int nx = st.first + dx[dir];
        int ny = st.second + dy[dir];
        if(OOB(nx,ny) && field[nx][ny] != '.') {
            st.first = nx; st.second = ny;
            break;
        }
    }
    
    bfs(st.first, st.second);
    cout << ax << ' ' << ay << ' ' << ap << '\n';
    return 0;
}

