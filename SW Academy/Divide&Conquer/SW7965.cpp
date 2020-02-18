#include <iostream>
#define MOD 1000000007
#define INF 1000000
using namespace std;
 
typedef long long ll;
ll p[INF + 1], sum[INF + 1];
bool check[INF + 1];
 
ll power(ll mit, ll jisu) {
    if(mit == 1) return 1;
    if(jisu == 0) return 1;
    if(jisu == 1) return mit;
    if(check[mit]) return p[mit];
     
    ll root = power(mit, jisu / 2) % MOD;
     
    p[mit] = ((root % MOD) * (root % MOD)) % MOD;
    check[mit] = true;
     
    if(jisu % 2 == 0) return p[mit];
    else return (p[mit] * mit) % MOD;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
     
    for(ll i = 1; i <= INF; i++) sum[i] = (sum[i - 1] % MOD + power(i, i) % MOD) % MOD;
     
    int T, N;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        cin >> N;
         
        cout << '#' << t << ' ' << sum[N] % MOD << '\n';
    }
    return 0;
}