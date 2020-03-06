#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;
ll dp[100002][2];
vector<vector<int> > v;

ll recur(int node, int color, int parent)
{
    ll &ret = dp[node][color];
    
    if(ret != -1) return ret;
    
    ret = 1;
    
    for(int i = 0; i < v[node].size(); i++)
    {
        int next = v[node][i];
        
        if(next == parent) continue;
        
        if(color == 0)
        {
            ret *= recur(v[node][i], 1, node) % MOD;
        }
        else
        {
            ret *= ((recur(v[node][i], 0, node) % MOD) + (recur(v[node][i], 1, node) % MOD)) % MOD;
        }
        ret %= MOD;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T, N, a, b;
    
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        memset(dp, -1, sizeof(dp));
        
        cin >> N;
        
        v.resize(N + 1);
        
        for(int i = 0; i < N - 1; i++)
        {
            cin >> a >> b;
            
            v[a].push_back(b);
            
            v[b].push_back(a);
        }
        cout << '#' << t << ' ' << (recur(1, 0, 0) + recur(1, 1, 0)) % MOD << '\n';
        
        v.clear();
    }
    return 0;
}