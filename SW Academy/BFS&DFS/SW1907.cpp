#include <iostream>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

int T, H, W;
char ch;
queue<pair<int, int> > q;

const int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int field[1001][1001];
bool check[1001][1001];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> T;
    
    for(int t = 1; t <= T; t++)
    {
        cin >> H >> W;
        
        for(int i = 0; i < H; i++)
        {
            for(int j = 0; j < W; j++)
            {
                cin >> ch;
                
                if(ch == '.')
                {
                    field[i][j] = 0;
                    
                    q.push(make_pair(i, j));
                }
                else field[i][j] = ch - '0';
            }
        }
        bool broken = true; int cnt = 0;
        
        while(broken)
        {
            broken = false;
            
            int qz = (int) q.size();
            
            while(qz--)
            {
                pair<int,int> oq = q.front();
                
                q.pop();
                
                for(int dir = 0; dir < 8; dir++)
                {
                    int nx = oq.first + dx[dir];
                    int ny = oq.second + dy[dir];
                    
                    if(0 <= nx && nx < H && W > ny && ny >= 0 && field[nx][ny] > 0)
                    {
                        field[nx][ny]--;
                        
                        if(field[nx][ny] <= 0 && !check[nx][ny])
                        {
                            check[nx][ny] = broken = true;
                             
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
            if(broken) cnt++;
        }
        memset(check,false,sizeof(check));
        
        cout << '#' << t << ' ' << cnt << '\n';
    }
    return 0;
}