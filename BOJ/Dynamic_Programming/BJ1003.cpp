#include <iostream>
#include <utility>
using namespace std;

int T, N;
pair<int,int> dp[45];
bool check[45];

pair<int,int> fib(int num)
{
    if(num == 0 || num == 1) return dp[num];
    
    if(check[num]) return dp[num];
    
    check[num] = true;
    
    return dp[num] = make_pair((fib(num - 2).first + fib(num - 1).first), (fib(num - 2).second + fib(num - 1).second));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    dp[0] = {1, 0}; dp[1] = {0, 1};
    
    fib(40);
    
    cin >> T;
    
    while(T--)
    {
        cin >> N;
        
        cout << dp[N].first << ' ' << dp[N].second << '\n';
    }
    return 0;
}