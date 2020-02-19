#include <iostream>
using namespace std;

int T, N, pre[1010], in[1010];

void post(int left, int right, int root)
{
    if(left > right) return;
    
    for(int i = left; i < right; i++)
    {
        if(in[i] == pre[root])
        {
            post(left, i, root + 1);
            
            post(i + 1, right, root + i - left + 1);
            
            cout << pre[root] << ' ';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> T;
    
    while(T--)
    {
        cin >> N;
        for(int i = 0; i < N; i++)
        {
            cin >> pre[i];
        }
        
        for(int i = 0; i < N; i++)
        {
            cin >> in[i];
        }
        post(0, N, 0);
        cout << '\n';
    }
    return 0;
}