#include <bits/stdc++.h>
using namespace std;

int n,m,g,r,MAX;
int field[55][55], crop[11];
pair<int,int> dist[55][55];
typedef struct {int x; int y; int c; } node;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
queue<node> q;
vector<pair<int,int> > v;

inline bool OOB(int xx, int yy) { return (0<= xx && xx < n && m > yy && yy >= 0); }

int bfs() {
    int ans = 0;

    while(!q.empty()) {
        node oq = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx = oq.x + dx[dir];
            int ny = oq.y + dy[dir];

            if(!OOB(nx,ny) || field[nx][ny] == 0 || dist[oq.x][oq.y].first == -1) continue;
            if(dist[nx][ny].first == 0) {
                dist[nx][ny] = make_pair(dist[oq.x][oq.y].first + 1, oq.c);
                q.push({nx,ny,oq.c});
            }
            else if(dist[nx][ny].first == dist[oq.x][oq.y].first + 1 && dist[nx][ny].second != dist[oq.x][oq.y].second){
                    dist[nx][ny].first = -1;
                    ans++;
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m >> g >> r;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
           cin >> field[i][j];
           if(field[i][j]==2) {
               v.push_back(make_pair(i,j));
           }
        }
    }
    int vs = (int) v.size();

    for(int i = vs - (g + r); i < vs; i++) {
        if(g>0) {
            crop[i] = 1;
            g--;
        }
        else if(r>0) {
            crop[i] = 2;
            r--;
        }
    }

    do {
        memset(dist,0,sizeof(dist));
        for(int i=0; i<vs; i++) {
            if(crop[i]==0) continue;
            else {
                dist[v[i].first][v[i].second] = make_pair(1,crop[i]);
                q.push({v[i].first, v[i].second, crop[i]});
            }
        }
        MAX = max(MAX, bfs());
    } while(next_permutation(crop, crop + vs));
    cout << MAX << '\n';
    return 0;
}