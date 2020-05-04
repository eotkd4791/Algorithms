#include <iostream>
#include <vector>

using namespace std;

typedef struct { int x; int y; int dir; } node;
int n, k, field[13][13];
node chess[11];
vector<int> fieldCur[13][13];
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};
bool flag = false;

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && n > yy && yy >= 0; }

bool check() {
    for(int i=0; i<k; i++)
        if(fieldCur[chess[i].x][chess[i].y].size() >= 4)
            return true;
    return false;
}

int getIndex(int x, int y, int i) {
    int j;
    for(j=0; j<fieldCur[x][y].size(); j++)
        if(fieldCur[x][y][j] == i) break;
    return j;
}

void white(node cur, int nx, int ny, int i) {
    int idx = getIndex(cur.x, cur.y, i);

    int sz = (int) fieldCur[cur.x][cur.y].size();
    for(int j = idx; j<sz; j++) {
        fieldCur[nx][ny].push_back(fieldCur[cur.x][cur.y][j]);
        chess[fieldCur[cur.x][cur.y][j]].x = nx;
        chess[fieldCur[cur.x][cur.y][j]].y = ny;
    }
    for(int j = 0; j<sz-idx; j++) {
        fieldCur[cur.x][cur.y].pop_back();
    }
}

void red(node cur, int nx, int ny, int i) {
    int idx = getIndex(cur.x, cur.y, i);
    
    int sz = (int) fieldCur[cur.x][cur.y].size();
    for(int j = sz-1; j>=idx; j--) {
        chess[fieldCur[cur.x][cur.y][j]].x = nx;
        chess[fieldCur[cur.x][cur.y][j]].y = ny;
        fieldCur[nx][ny].push_back(fieldCur[cur.x][cur.y][j]);
    }
    for(int j = 0; j<sz-idx; j++) {
        fieldCur[cur.x][cur.y].pop_back();
    }
}

void blue(node cur, int i) {
    int od = cur.dir;
    od % 2 == 0 ? od-- : od++;
    chess[i].dir = cur.dir = od;
    
    int nx = cur.x + dx[od];
    int ny = cur.y + dy[od];
    
    if(OOB(nx,ny) && field[nx][ny] != 2)
        field[nx][ny] == 0 ? white(cur, nx, ny, i) : red(cur, nx, ny, i);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     
    cin >> n >> k;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> field[i][j];

    for(int i=0; i<k; i++) {
        node inp;
        cin >> inp.x >> inp.y >> inp.dir;
        inp.x--; inp.y--;
        chess[i] = inp;
        fieldCur[inp.x][inp.y].push_back(i);
    }
    
    int res = 0;
    while(res++ <= 1000) {
        for(int i=0; i<k; i++) {
            node cur = chess[i];
            int nx= cur.x + dx[cur.dir];
            int ny = cur.y + dy[cur.dir];
            
            if(OOB(nx,ny)) {
                if(field[nx][ny] == 0) white(cur, nx, ny, i);
                else if(field[nx][ny] == 1) red(cur, nx, ny, i);
                else blue(cur, i);
            }
            else blue(cur, i);

            if(check()) {
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    cout <<  (res > 1000 ? -1 : res) << '\n';
    return 0;
}
