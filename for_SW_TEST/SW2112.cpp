#include <iostream>
#include <cstring>
using namespace std;

int field[15][22], d, w, k, ans;

inline bool check() {
    for(int j = 0; j < w; j++) {
        int cnt = 1;
        for(int i = 1; i < d; i++) {
            if(field[i][j] == field[i - 1][j]) {
                cnt++;
                if(cnt == k) break;
            }
            else cnt = 1;
        }
        if(cnt != k) return false;
    }
    return true;
}

void recur(int idx, int cnt) {
    if (idx > d || cnt > ans) return;
    if (check()) ans = ans > cnt ? cnt : ans;
    
    int tmp[15][22] = {};
    
    memcpy(tmp, field, sizeof(field));
    for (int i = 0; i < 3; i++) {
        if (i == 0) recur(idx + 1, cnt);
        else {
            for(int j = 0; j < w; j++) field[idx][j] = i - 1;
            recur(idx + 1, cnt + 1);
        }
    }
    memcpy(field, tmp, sizeof(field));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; cin >> T;
    
    for(int t = 1; t <= T; t++) {
        ans = 987654321;
     
        cin >> d >> w >> k;
        for(int i = 0; i < d; i++)
            for(int j = 0; j < w; j++)
                cin >> field[i][j];
            
        recur(0, 0);
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}
