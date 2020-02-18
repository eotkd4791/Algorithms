#include <iostream>
#define MOD 1000000007
#define INF 1000000

using namespace std;
typedef long long ll;

int T, N;
ll sum[INF + 1];

ll power(ll mit, ll jisu)
{
    if(jisu == 0) return 1;
    if(jisu == 1) return mit;
    
    ll root = power(mit, jisu / 2) % MOD;
    
    if(jisu % 2 == 1) return (root * ((root * mit) % MOD)) % MOD;
    
    else return (root * root) % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    sum[1] = 1; sum[2] = 5;
    for(ll i = 3; i <= INF; i++)
    {
        sum[i] = (sum[i - 1] + power(i, i)) % MOD;
    }
    
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> N;
        cout << '#' << t << ' ' << sum[N] % MOD << '\n';
    }
    return 0;
}