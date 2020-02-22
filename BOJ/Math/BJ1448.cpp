#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);
    
    bool flag = false;
    
    for(int i = N - 1; i >= 2; i--)
    {
        if(arr[i] < arr[i-1] + arr[i-2])
        {
            cout << arr[i] + arr[i-1] + arr[i-2] << '\n';
            
            flag = true;
            
            break;
        }
    }
    
    if(!flag) cout << -1 << '\n';
    return 0;
}
