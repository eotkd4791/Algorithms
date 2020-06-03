#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
using namespace std;

int field[105][105], N, MAX, cnt;
vector<pair<int,int> > st;
vector<pair<int,int> > hole[5]; // 번호, 쌍
int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};

inline bool OOB(int x, int y) { return 0 <= x && x < N && N > y && y >= 0; }
inline pair<bool, int> getDir(int block, int dir) {
    if(block == 1) {
        if(dir==2) return make_pair(false, 1);
        if(dir==3) return make_pair(false, 0);
    }
    else if(block==2) {
        if(dir==0) return make_pair(false, 1);
        if(dir==3) return make_pair(false, 2);
    }
    else if(block==3) {
        if(dir==0) return make_pair(false, 3);
        if(dir==1) return make_pair(false, 2);
    }
    else if(block==4) {
        if(dir==1) return make_pair(false, 0);
        if(dir==2) return make_pair(false, 3);
    }
    return make_pair(true,(dir + 2) % 4);
}

void init() {
    MAX = 0; cnt = 0;
    memset(field, 0, sizeof(field));
    st.clear();
    for(int i = 0; i < 5; i++) hole[i].clear();
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    for(int t=1; t<=T; t++) {
        cin >> N;
        init();
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                cin >> field[i][j];
                if(field[i][j] == 0) {
                    st.push_back(make_pair(i,j));
                }
                if(6 <= field[i][j] && field[i][j] <= 10) {
                    hole[field[i][j] - 6].push_back(make_pair(i,j));
                }
            }
        }
        for(int i=0; i<st.size(); i++) {
            int sx = st[i].first;
            int sy = st[i].second;
            
            for(int dir=0; dir<4; dir++) {
                int nx = sx;
                int ny = sy;
                int ndir = dir;
                  
                while(1) {
                    nx += dx[ndir];
                    ny += dy[ndir];
                    
                    if((nx == sx && ny == sy) || field[nx][ny] == -1) break; // 블랙홀이나 처음 위치
                    if(1 <= field[nx][ny] && field[nx][ny] <= 5) { //벽, 블록에 부딪힘
                        cnt++;
                        pair<bool, int> tmp = getDir(field[nx][ny], ndir);
                        if(tmp.first) {
                            cnt = cnt * 2 - 1;
                            break;
                        }
                        ndir = tmp.second;
                    }
                    if(!OOB(nx, ny)) {
                        cnt++;
                        cnt = cnt * 2 - 1;
                        break;
                    }
                    if(6 <= field[nx][ny] && field[nx][ny] <= 10) { // 웜홀
                        int idx = field[nx][ny] - 6;
                        for(int j = 0; j < hole[idx].size(); j++) {
                            if(hole[idx][j] == make_pair(nx, ny)) continue;
                            nx = hole[idx][j].first;
                            ny = hole[idx][j].second;
                            break;
                        }
                    }
                }
                MAX = MAX < cnt ? cnt : MAX;
                cnt = 0;
            }
        }
        cout << '#' << t << ' ' << MAX << '\n';
    }
    return 0;
}

