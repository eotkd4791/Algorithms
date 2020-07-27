#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

ll solution(int n, vector<int> v) {
    sort(v.begin(), v.end());
    ll ans = 0,
        left = 1,
        right = v[v.size()-1] * (ll) n;
    
    while(left <= right) {
        ll time = (left + right) / 2;
        ll sum = 0;
        
        for(int i = 0; i < v.size(); i++) 
            sum += time / v[i];

        if(sum >= n) {
            ans = time;
            right = time - 1;
        }
        else left = time + 1;
    }
    return ans;
}
