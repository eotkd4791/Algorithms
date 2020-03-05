#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T; int dist[202] = {1, }; int add = 3;
    int x1, y1, x2, y2;
    
    for(int i = 1; i <= 200; i++)
    {
        dist[i] = dist[i - 1] + add;
        
        if(add == 3) add = 1;
        
        else add = 3;
    }
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        
        int res = 0; int xpos = x2 - x1; int ypos = y2 - y1;
        
        int dx = 1, dy = 1;
        
        if(xpos < 0) dx *= (-1);
        
        if(ypos < 0) dy *= (-1);
        
        while(x1 - x2 != 0 && y1 - y2 != 0)
        {
            x1 += dx; y1 += dy;
            
            res += 2;
        }
        int d = (x1 - x2) + (y1 - y2);
        
        if(d < 0) d *= (-1);
        
        if(d != 0) res += dist[d - 1];
        
        cout << '#' << t << ' ' << res << '\n';
    }
    return 0;
}
