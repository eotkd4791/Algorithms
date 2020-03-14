#include <iostream>
using namespace std;

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T, n;
    cin >> T;
    while(T--) 
    {
        cin >> n;
        
        cout << 1 << ' ' << n-1 << '\n';
    }
    return 0;
}