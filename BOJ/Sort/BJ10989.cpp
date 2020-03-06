#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int n, arr[10001] = {};
    cin >> n;
    
    int a, MAX = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        
        arr[a]++;
        
        MAX = MAX < a ? a : MAX;
        
    }
    for(int i = 1; i <= MAX; i++)
    {
        if(arr[i] == 0) continue;
        
        while(arr[i]--) cout << i << '\n';
    }
    return 0;
}