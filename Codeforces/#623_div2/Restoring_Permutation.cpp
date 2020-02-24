#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T, n;
    
    cin >> T;
    
    while(T--)
    {
        cin >> n;
        
        int b[202] = {}; bool check[202] = {}; vector<int> v;
        
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            
            check[b[i]] = true;
        }
        
        for(int i = 0; i < n; i++)
        {
            v.push_back(b[i]);
            
            int tmp = b[i];
            
            for(int j = tmp; j <= 2 * n; j++)
            {
                if(!check[j])
                {
                    check[j] = true;
                    
                    v.push_back(j);
                    
                    break;
                }
            }
            
        }
        int vs = (int) v.size();
        
        if(vs == 2 * n) for(int i = 0; i < vs; i++) cout << v[i] << ' ';
        
        else cout << -1;
        
        cout << '\n';
    }
    return 0;
}