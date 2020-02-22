#include <iostream>
#include <algorithm>
using namespace std;

int N, M;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N >> M;
    
    if(N == 1) cout << 1 << '\n';
    
    else if(N == 2) cout << min(4, (M + 1) / 2) << '\n';
    
    else
    {
        if(M <= 6) cout << min(4, M) << '\n';
        
        else cout << M - 2 << '\n';
    }
    return 0;
}
