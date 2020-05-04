#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct { int x; int y; int dir; bool bottom; } node;
int n, k, field[13][13];
node chess[11];
vector<int> fieldCur[13][13];
const int dx[] = {0, 0, 0, -1, 1};
const int dy[] = {0, 1, -1, 0, 0};

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && n > yy && yy >= 0; }

void white(node cur, int nx, int ny) {
    if(!fieldCur[nx][ny].empty()) chess[fieldCur[cur.x][cur.y][0]].bottom = false;
    for(int j=0; j<fieldCur[cur.x][cur.y].size(); j++) {
        int idx = fieldCur[cur.x][cur.y][j];
        fieldCur[nx][ny].push_back(idx);
        chess[idx].x = nx;
        chess[idx].y = ny;
    }
    fieldCur[cur.x][cur.y].clear();
}

void red(node cur, int nx, int ny) {
    reverse(fieldCur[cur.x][cur.y].begin(), fieldCur[cur.x][cur.y].end());
    chess[fieldCur[cur.x][cur.y].back()].bottom = false;
    
    chess[fieldCur[cur.x][cur.y][0]].bottom = fieldCur[nx][ny].empty() ? true : false;
    for(int j=0; j<fieldCur[cur.x][cur.y].size(); j++) {
        int idx = fieldCur[cur.x][cur.y][j];
        fieldCur[nx][ny].push_back(idx);
        chess[idx].x = nx;
        chess[idx].y = ny;
    }
    fieldCur[cur.x][cur.y].clear();
}

void blue(node cur, int i) {
    int od = chess[i].dir;
    chess[i].dir = od % 2 == 0 ? --od : ++od;

    int nx = cur.x + dx[od];
    int ny = cur.y + dy[od];
    
    if(OOB(nx,ny) && field[nx][ny] != 2)
        field[nx][ny] == 0 ? white(cur, nx, ny) : red(cur, nx, ny);
}

bool check() {
    for(int i=0; i<k; i++)
        if(fieldCur[chess[i].x][chess[i].y].size() >= 4)
            return true;
    return false;
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
        inp.x--; inp.y--; inp.bottom = true;
        chess[i] = inp;
        fieldCur[inp.x][inp.y].push_back(i);
    }
    
    int res = 0; bool flag = false;
    while(res++ <= 1000) {
        for(int i=0; i<k; i++) {
            node cur = chess[i];
            
            if(!cur.bottom) continue;
            
            int nx = cur.x + dx[cur.dir];
            int ny = cur.y + dy[cur.dir];
            if(OOB(nx,ny)) {
                if(field[nx][ny] == 0) white(cur, nx, ny);
                else if(field[nx][ny] == 1) red(cur, nx, ny);
                else blue(cur, i);
            }
            else blue(cur, i);
            
            if(check()) {
                flag=true;
                break;
            }
        }
        if(flag) break;
    }
    cout <<  (res > 1000 ? -1 : res) << '\n';
    return 0;
}

