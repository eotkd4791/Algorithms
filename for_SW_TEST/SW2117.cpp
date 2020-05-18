#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int N, M, field[22][22], house, MAX;
const int dx[] = {0, 0, -1, 1}, dy[] = {1, -1, 0, 0};

inline bool OOB(int x, int y) { return 0 <= x && x < N && N > y && y >= 0; }

int getProfit(int p) { return p * p + (p - 1) * (p - 1); }

void bfs(int x, int y, int limit) {
    queue<pair<int, int> > q;
    bool check[22][22] = {};
    
    q.push(make_pair(x, y));
    check[x][y] = true;
    
    house = field[x][y] ? 1 : 0;
    int dist = 1;

    while(!q.empty()) {
        if(dist > limit) break;
        if(house * M >= getProfit(dist))
            MAX = MAX < house ? house : MAX;
        
        int qz = (int) q.size();
        while(qz--) {
            pair<int, int> oq = q.front();
            q.pop();
            
            for(int dir = 0; dir < 4; dir++) {
                int nx = oq.first + dx[dir];
                int ny = oq.second + dy[dir];
                if(!OOB(nx,ny) || check[nx][ny]) continue;
                
                if(field[nx][ny]) house++;
                check[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
        dist++;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    
    for(int t = 1; t <= T; t++) {
        MAX = 0;
        
        cin >> N >> M;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                cin >> field[i][j];
        
        int limit = N % 2 ? N : N + 1;
        
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                bfs(i, j, limit);
                
        cout << '#' << t << ' ' << MAX << '\n';
    }
    return 0;
}

