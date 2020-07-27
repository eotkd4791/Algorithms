#include <vector>
#include <algorithm>
#include <climits>
#define ll long long
using namespace std;

ll bs(ll start, ll end) {
    return (start + end) / 2;
}

ll solution(int n, vector<int> v) {
    ll ans = LLONG_MAX,
        MIN = *min_element(v.begin(), v.end()),
        MAX = MIN * n;
    
    ll left = MIN, right = MAX;
    ll time = bs(left, right);
    
    while(left<=right) {
        ll sum = 0;
        for(int i=0; i<v.size(); i++) 
            sum += time / v[i];

        if(sum >= n) {
            if(ans == time) break;
            ans = min(ans, time);
            right = time;
            time = bs(left, right);
        }
        else {
            left = time + 1;
            time = bs(left, right);
        }
    }
    return ans;
}