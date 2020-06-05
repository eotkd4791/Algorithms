#include <iostream>
#include <cstring>
using namespace std;

typedef struct { int y; int x; int d; int k; bool flag; } atom;
atom arr[1001];
const int MAX = 4000;
int N, sum, field[MAX + 1][MAX + 1];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

inline bool OOB(int x, int y) { return 0 <= x && x <= MAX && 0 <= y && y <= MAX; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    for(int t=1; t<=T; t++) {
        sum=0;
        memset(field, -1, sizeof(field));
        
        cin >> N;
        for(int i = 0; i < N; i++) {
            int y, x, d, k;
            cin >> y >> x >> d >> k;
            arr[i] = { (x + 1000) * 2, (y + 1000) * 2, d, k, false };
        }
        
        for(int i=0; i<=MAX; i++) {
            bool check = false;
            for(int j=0; j<N; j++) field[arr[j].x][arr[j].y] = -1;
            
            for(int j=0; j<N; j++) {
                atom cur = arr[j];
                if(cur.flag) continue;
                check = true;
                int nx = cur.x + dx[cur.d];
                int ny = cur.y + dy[cur.d];
                if(OOB(nx,ny)) {
                   if(field[nx][ny] > -1) {
                        int idx = field[nx][ny];
                        if(!arr[idx].flag) {
                            arr[idx].flag = true;
                            sum += arr[idx].k;
                        }
                        arr[j].flag = true;
                        sum += cur.k;
                    }
                    else {
                        field[nx][ny] = j;
                        arr[j].x = nx;
                        arr[j].y = ny;
                    }
                }
                else arr[j].flag = true;
            }
            if(!check) break;
        }
        cout << '#' << t << ' ' << sum << '\n';
    }
    return 0;
}

