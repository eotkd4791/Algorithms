#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T, n, arr[50001] = {};
    
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> n;
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int ans = 0; int inc = 0; int dec = 0; bool isSummit = false;

        for(int i = 0; i < n - 1; i++)
        {
            if(arr[i] < arr[i + 1])
            {
                if(!isSummit) inc++;
                
                else
                {
                    ans += inc * dec;
                    
                    inc = 1; dec = 0;
                    
                    isSummit = false;
                }
            }
            else
            {
                if(!isSummit)
                {
                    if(inc > 0)
                    {
                        isSummit = true;

                        dec++;
                    }
                }
                else dec++;
            }
        }
        if(isSummit) ans += inc * dec;
        cout << '#' << t << ' ' << ans << '\n';
    }
    return 0;
}
