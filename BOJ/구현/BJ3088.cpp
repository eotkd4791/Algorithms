#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000;
int n, pot[INF/3][3];
bool check[INF+1];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> pot[i][j];
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
        if(!check[pot[i][0]] && !check[pot[i][1]] && !check[pot[i][2]]) ans++;

        check[pot[i][0]] = true;
        check[pot[i][1]]= true;
        check[pot[i][2]]= true;
    }
    cout << ans << '\n';
    return 0;
}