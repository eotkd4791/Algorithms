#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#define INF 987654321
using namespace std;

int N, MIN = INF, field[15];
bool ischecked[15], connected[15][15], check[15];

bool bfs(vector<int> v, bool flag) {
    memset(check,false,sizeof(check));
    queue<int> q;
    q.push(v[0]);
    check[v[0]] = true;
    
    int cnt = 1;
    while(!q.empty()) {
        int oq = q.front();
        q.pop();
        
        for(int i=1; i<=N; i++) {
            if(!check[i] && connected[oq][i] && ischecked[i] == flag) {
                check[i]=true;
                cnt++;
                q.push(i);
            }
        }
    }
    if(cnt == v.size()) return true;
    else return false;
}

void cmb(int idx, int cnt) {
    if(idx > N) return;
    if(1 <= cnt && cnt < N) {
        int sum1=0;
        int sum2=0;
        vector<int> a,b;
        
        for(int i=1; i<=N; i++) {
            if(!ischecked[i]) {
                sum1+=field[i];
                a.push_back(i);
            }
            else {
                sum2+=field[i];
                b.push_back(i);
            }
        }
        if(bfs(a,false) && bfs(b,true))
            MIN = min(MIN, abs(sum1-sum2));
        
    }
    ischecked[idx] = true;
    cmb(idx + 1, cnt + 1);
    ischecked[idx] = false;
    cmb(idx + 1, cnt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> field[i];
    
    int adjcnt, a;
    for(int i = 1; i <= N; i++) {
        cin >> adjcnt;
        for(int j = 0; j < adjcnt; j++) {
            cin >> a;
            connected[i][a]=true;
            connected[a][i]=true;
        }
    }
    cmb(1, 0);
    if(MIN == INF) MIN = -1;
    cout << MIN << '\n';
    return 0;
}