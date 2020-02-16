#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

typedef long long ll;
int T, N, M, K;
pair<ll,int> field[101][101];
vector<pair<ll, int> > tmp[101][101];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

inline bool OOB(int xx, int yy) { return (0 == xx || xx == N - 1 || N - 1 == yy || yy == 0); }

int newDir(int od) {
    if(od == 0) return 1;
    if(od == 1) return 0;
    if(od == 2) return 3;
    return 2;
}

void moving() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(field[i][j].first > 0) {
                int nx = i + dx[field[i][j].second];
                int ny = j + dy[field[i][j].second];
                
                pair<ll, int> temp = field[i][j];
                if(OOB(nx,ny)) {
                    temp.first /= 2;
                    temp.second = newDir(temp.second);
                }
                tmp[nx][ny].push_back(temp);
            }
        }
    }
}

void afterMoving() {
    memset(field,0,sizeof(field));
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(tmp[i][j].empty()) continue;
            if(tmp[i][j].size() > 1) {
                sort(tmp[i][j].begin(), tmp[i][j].end(), greater<pair<ll,int> >());
                int dir = tmp[i][j][0].second;
                ll sum=0;
                for(int k = 0; k < tmp[i][j].size(); k++)
                    sum += tmp[i][j][k].first;
                
                field[i][j] = make_pair(sum,dir);
                tmp[i][j].clear();
            }
            else {
                field[i][j] = make_pair(tmp[i][j][0].first, tmp[i][j][0].second);
                tmp[i][j].pop_back();
            }
        }
    }
}

void init() {
    memset(field,0,sizeof(field));
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            tmp[i][j].clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> N >> M >> K;
        
        init();
        int a,b,c,d;
        for(int i=0; i<K; i++) {
            cin >> a >> b >> c >> d;
            field[a][b] = make_pair(c,--d);
        }
        
        while(M--) {
            moving();
            afterMoving();
        }
        ll ans=0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                ans += field[i][j].first;
            
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}
