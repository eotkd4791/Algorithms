#include <bits/stdc++.h>
using namespace std;

int n, m, island;
int field[15][15];
int land[15][15];
typedef struct { int br; int de; int ar; }node;
vector<node> krus;
vector<vector<pair<int, int> > > v;
int dx[] = {-1,0,1,0};
int dy[] = {0,-1,0,1};
int parent[10],height[10];

bool cmp (node a, node b) { return a.br < b.br; }
inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && m > yy && yy >= 0;}

void bfs(int x, int y) {
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    land[x][y] = island;

    while(!q.empty()) {
        pair<int,int> oq = q.front();
        q.pop();

        for(int dir=0; dir<4; dir++) {
            int nx=oq.first+dx[dir];
            int ny=oq.second+dy[dir];

            if(!OOB(nx,ny) || land[nx][ny] > 0 || field[nx][ny] == 0) continue;

            land[nx][ny] = island;
            q.push(make_pair(nx,ny));
        }
    }
}

int find(int v) {
    if(parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int u, int v) {
    int ru = find(u);
    int rv = find(v);

    if(height[ru] > height[rv]) {
        parent[rv] = ru;
    }
    else if(height[ru] < height[rv]) {
        parent[ru] = rv;
    }
    else {
        parent[ru] = rv;
        height[rv] = ++height[ru];
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> field[i][j];


    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(land[i][j]==0 && field[i][j] == 1) {
                island++;
                bfs(i, j);
            }
        }
    }
    v.resize(island + 1);

    for(int i=1; i<=island; i++) {
        parent[i] = i;
        height[i] = 1;
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(field[i][j] == 1) {
                for(int dir=0; dir<4; dir++) {
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(OOB(nx,ny) && field[nx][ny] == 0) {
                        v[land[i][j]].push_back(make_pair(i, j));
                        break;
                    }
                }
            }
        }
    }

    for(int i = 1; i <= island; i++) {
        for(int j = 1; j <= island; j++) {
            if(i == j) continue;

            for(int k = 0; k < v[i].size(); k++) {
                for(int l = 0; l < v[j].size(); l++) {
                    pair<int,int> cur = v[i][k], dest = v[j][l];
                    int od;
                    if(cur.first == dest.first) od = (cur.second > dest.second) ? 1 : 3;

                    else if(cur.second == dest.second) od = (cur.first > dest.first) ? 0 : 2;

                    int bridge=0;
                    if(od == 0 || od == 2) {
                        int nx = cur.first + dx[od];
                        while(nx != dest.first && field[nx][cur.second]==0) {
                            nx += dx[od];
                            bridge++;
                            if(!OOB(nx,cur.second)) {
                                bridge = 0;
                                break;
                            }
                            if(field[nx][cur.second] == 1 && land[nx][cur.second] != land[dest.first][dest.second]) {
                                bridge = 0;
                                break;
                            }
                            if(land[nx][cur.second] == land[dest.first][dest.second]) {
                                if(bridge >= 2) krus.push_back({bridge, i, j });
                                bridge = 0;
                                break;
                            }
                        }
                    }
                    else {
                        int ny = cur.second + dy[od];
                        while(ny!=dest.second && field[cur.first][ny]==0) {
                            ny += dy[od];
                            bridge++;
                            if(!OOB(cur.first,ny)) {
                                bridge = 0;
                                break;
                            }
                            if(field[cur.first][ny] == 1 && land[cur.first][ny] != land[dest.first][dest.second]) {
                                bridge = 0;
                                break;
                            }
                            if(land[cur.first][ny] == land[dest.first][dest.second]) {
                                if(bridge >= 2) krus.push_back({bridge, i, j });
                                bridge = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    if(!krus.empty()) {
        sort(krus.begin(), krus.end(), cmp);
        ans = 0;
        for(int i=0; i<krus.size(); i++) {
            if(find(krus[i].de) == find(krus[i].ar)) continue;
            merge(krus[i].de, krus[i].ar);
            ans += krus[i].br;
        }
        for(int i=1; i<=island; i++) {
            int tmp = find(i);
        }
        for(int i=1; i<island; i++) {
           if(parent[i] != parent[i+1]) {
               ans = -1;
               break;
           }
        }
    }
    cout << ans << '\n';
    return 0;
}
