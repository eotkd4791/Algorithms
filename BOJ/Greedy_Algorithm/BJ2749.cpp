#include <iostream>
#define MOD 1000000
using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    ll cur = 0, prev = 1, pprev = 0, input = 0, cyc = 0;
    
    cin >> input;
    
    if(input == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    if(MOD <= input)
    {
        for(ll i = 2; i <= input; i++)
        {
            cur = ((prev % MOD) + (pprev % MOD)) % MOD;
            
            pprev = prev;
            
            prev = cur;
            
            if(pprev == 0 && prev == 1)
            {
                cyc = i - 1;

                break;
            }
        }
        
        input %= cyc;
    }
    
    cur = 0; prev = 1; pprev = 0;

    for(ll i = 2; i <= input; i++)
    {
        cur = ((prev % MOD) + (pprev % MOD)) % MOD;
        
        pprev = prev;
        
        prev = cur;
    }
    cout << cur << '\n';
    return 0;
}
