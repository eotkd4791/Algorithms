#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    int T,a,b,p;
    string s;
    
    cin >> T;
    
    while(T--)
    {
        cin >> a >> b >> p >> s;
        
        int MIN = (int) s.size();
        
        s.pop_back();
        
        while(!s.empty())
        {
            char idx = s.back();
            
            if(idx == 'A')
            {
                if(p >= a)
                {
                    p -= a;
                    
                    while(idx == s.back() && !s.empty()) s.pop_back();
                    
                    MIN = (int) s.size() + 1;
                }
                else
                {
                    break;
                }
            }
            else //B
            {
                if(p >= b)
                {
                    p -= b;
                    
                    while(idx == s.back() && !s.empty()) s.pop_back();
                    
                    MIN = (int) s.size() + 1;
                }
                else
                {
                    break;
                }
            }
        }
        cout << MIN << '\n';
    }
    return 0;
}
