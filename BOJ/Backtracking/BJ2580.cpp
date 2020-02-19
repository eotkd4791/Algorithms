#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int field[10][10];
bool h[10][10], v[10][10], sq[10][10], flag;
vector<pair<int,int> > zero;

void recur(int cnt)
{
    if(cnt == zero.size())
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                cout << field[i][j] << ' ';
            }
            cout << '\n';
        }
        
        flag = true;
        
        return;
    }
    
    int i = zero[cnt].first;
    
    int j = zero[cnt].second;
    
    for(int k = 1; k <= 9; k++)
    {
        if(h[i][k] || v[j][k] || sq[(i / 3) * 3 + (j / 3)][k]) continue;
        
        h[i][k] = true;
        
        v[j][k] = true;
        
        sq[(i / 3) * 3 + (j / 3)][k] = true;
        
        field[i][j] = k;
        
        recur(cnt + 1);
        
        if(flag) return;
        
        field[i][j] = 0;
        
        h[i][k] = false;
        
        v[j][k] = false;
        
        sq[(i / 3) * 3 + (j / 3)][k] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            cin >> field[i][j];
            
            if(field[i][j] != 0)
            {
                h[i][field[i][j]] = true;
                
                v[j][field[i][j]] = true;
                
                sq[(i / 3) * 3 + (j / 3)][field[i][j]] = true;
            }
            else
            {
                zero.push_back(make_pair(i, j));
            }
        }
    }
    recur(0);
    return 0;
}