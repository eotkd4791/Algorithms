#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

int n, m, nodeCnt, field[11][11], graph[11][11], parent[7], height[7];
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater <pair<int, pair<int, int> > > > pq;

inline bool OOB(int xx, int yy) { return 0 <= xx && xx < n && m > yy && yy >= 0; }

void bfs(int x, int y) 
{
    graph[x][y] = nodeCnt + 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));

    while (!q.empty()) 
    {
        pair<int, int> oq = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) 
        {
            int nx = oq.first + dx[dir];
            int ny = oq.second + dy[dir];

            if (!OOB(nx, ny) || graph[nx][ny] > 0 || field[nx][ny] == 0) continue;
            q.push(make_pair(nx, ny));
            graph[nx][ny] = nodeCnt + 1;
        }
    }
}

int find(int u) 
{
    if(parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) 
{
    int ru = find(u);
    int rv = find(v);

    if(height[ru] > height[rv]) parent[rv] = ru;
    
    else if(height[ru] < height[rv]) parent[ru] = rv;
    else 
    {
        parent[ru] = rv;
        height[rv] = ++height[ru];
    }
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> field[i][j];

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (graph[i][j] == 0 && field[i][j] > 0) 
            {
                bfs(i, j);
                nodeCnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (field[i][j] > 0) 
            {
                int curNode = graph[i][j];

                for (int dir = 0; dir < 4; dir++) 
                {
                    int ox = i + dx[dir];
                    int oy = j + dy[dir];

                    if(graph[ox][oy] == curNode) continue;

                    int weight = 0;
                    while (OOB(ox, oy)) 
                    {
                        if (graph[ox][oy] == curNode) break;

                        else if (graph[ox][oy] > 0) 
                        {
                            if(weight > 1) pq.push(make_pair(weight, make_pair(curNode, graph[ox][oy])));

                            break;

                        } 
                        else 
                        {
                            ox += dx[dir];
                            oy += dy[dir];
                            weight++;
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= nodeCnt; i++) 
    {
        parent[i] = i;
        height[i] = 1;
    }
    int ans=0, edge=0;

    while(!pq.empty()) 
    {
        int weight = pq.top().first;
        int start = pq.top().second.first;
        int end = pq.top().second.second;
        pq.pop();

        if(find(start) == find(end)) continue;
        merge(start, end);
        edge++;
        ans+=weight;
    }
    if(edge != nodeCnt - 1) ans = -1;
    cout << ans << '\n';
    return 0;
}