#include <iostream>
#include <map>
using namespace std;
 
typedef long long ll;
const int INF = 100000;
map<int, ll> m;
int n;
int arr[2 * INF + 10];
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        int idx = arr[i]-i;
        if(m.find(idx) == m.end()) m.insert(make_pair(idx, arr[i]));
        else m.find(idx)->second += arr[i];
    }
    ll MAX = 0;
    for(auto it = m.begin(); it != m.end(); it++) MAX = MAX < it->second ? it->second : MAX;
    cout << MAX << '\n';
    return 0;
}