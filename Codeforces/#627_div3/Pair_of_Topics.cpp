#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;

int upperBound(int *arr, int left, int right, int target) 
{
    int mid;

    while(left < right) 
    {
        mid = (left + right) / 2;

        if(arr[mid] <= target) left = mid + 1;

        else right = mid;
    }
    return right;
}

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    int a[200001] = {};
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    int b; ll ans = 0;

    for(int i = 0; i < n; i++) 
    {
        cin >> b;
        a[i] -= b;
    }
    sort(a, a + n);

    for(ll i = 0; i < n - 1; i++) 
    {
        if(a[i] > 0) 
        {
            ans += (n - 1 - i) * (n - i) / 2;
            break;
        }
        else 
        {
            int idx = upperBound(a, i, n, -a[i]);

            ans += n - 1 - idx + 1;
        }
    }
    cout << ans << '\n';
    return 0;
};
