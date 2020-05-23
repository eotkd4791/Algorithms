#include <iostream>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;

queue<pair<int, int> > q;
int h, w, ans;
char field[101][101];
bool check[101][101], key[30];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};


inline bool OOB(int x, int y) { return 0 <= x && x <= h + 1 && w + 1 >= y && y >= 0; }

void init() {
    memset(check, false, sizeof(check));
    memset(key, false, sizeof(key));
    memset(field, '.', sizeof(field));
    ans = 0;
}

void bfs() {
    queue<pair<int,int> > door[30];
    while(!q.empty()) {
        pair<int, int> oq = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = oq.first + dx[dir];
            int ny = oq.second + dy[dir];

            if(!OOB(nx, ny) || check[nx][ny] || field[nx][ny] == '*') continue;
            check[nx][ny] = true;

            if('A' <= field[nx][ny] && field[nx][ny] <= 'Z') {
                int idx = field[nx][ny] - 'A';
                key[idx] ? q.push(make_pair(nx, ny)) : door[idx].push(make_pair(nx, ny));
            }
            else if('a' <= field[nx][ny] && field[nx][ny] <= 'z') {
                int idx = field[nx][ny] - 'a';
                if(!key[idx]) {
                    key[idx] = true;
                    while(!door[idx].empty()) {
                        pair<int, int> od = door[idx].front();
                        door[idx].pop();
                        q.push(od);
                    }
                }
                q.push(make_pair(nx, ny));
            }
            else { // . $
                if(field[nx][ny] == '$') ans++;
                q.push(make_pair(nx, ny));
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int T;
    cin >> T;

    while(T--) {
        init();
        cin >> h >> w;
        for(int i = 1; i <= h; i++) {
            for(int j = 1; j <= w; j++) {
                cin >> field[i][j];
            }
        }
        string inp;
        cin >> inp;
        if(inp[0] != '0') {
            for(int i = 0; i < inp.size(); i++) {
                int idx = inp[i] - 'a';
                key[idx] = true;
            }
        }
        q.push(make_pair(0, 0));
        bfs();
        cout << ans << '\n';
    }
    return 0;
}
