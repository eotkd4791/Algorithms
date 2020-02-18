#include <iostream>
#include <algorithm>
using namespace std;

int N, white, blue;
int field[129][129];

void recur(int sx, int sy, int fx, int fy)
{
    if(sx == fx || sy == fy) return;
    
    if( (sx + fx) / 2 == 0 && (sy + fy) / 2 == 0)
    {
        if(field[sx][sy] == 0) white++;
        
        else blue++;
        
        return;
    }
    
    int tmp = field[sx][sy];
    
    bool flag = true;
    
    for(int i = sx; i < fx; i++)
    {
        for(int j = sy; j < fy; j++)
        {
            if(tmp != field[i][j]) flag = false;
        }
    }
    
    if(flag)
    {
        if(tmp == 0) white++;
        
        else blue++;
    }
    
    else
    {
        recur(sx, sy, (sx + fx) / 2, (sy + fy) / 2);
        
        recur(sx, (sy+fy) / 2, (sx + fx) / 2, fy);
        
        recur((sx+fx)/2, sy, fx, (sy + fy) / 2);
        
        recur((sx+fx)/2, (sy + fy)/2, fx, fy);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> field[i][j];
        }
    }
    
    recur(0, 0, N, N);
    
    cout << white << '\n' << blue;
    return 0;
}
