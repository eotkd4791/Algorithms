#include <iostream>
#include <cmath>
#include <vector>
#define INF 100001
using namespace std;

int N;
typedef long long ll;
bool pCheck[100001];

void getPrime() {
    pCheck[0] = pCheck[1] = true;
    for(int i=2; i<=INF; i++) {
        if(!pCheck[i]) {
            for(int j=i+i; j<=INF; j+=i)
                pCheck[j] = true;
        }
    }
}

ll recur(int n) {
    vector<int> v,c;
    ll ans = 1;
    
    for(int i=2; i<=INF; i++) {
        if(!pCheck[i] && n % i == 0) {
            v.push_back(i);
            
            int cnt =0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            c.push_back(cnt);
        }
    }
    for(int i = 0; i < v.size(); i++)
        ans *= ( (int) (pow(v[i], c[i])) - (int) (pow(v[i],c[i]-1)) );
    
    if(n==1) return ans;
    else  return ans * (n-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    getPrime();
    
    while(1) {
        cin >> N;
        if(N==0) break;
        cout << recur(N) << '\n';
    }
    return 0;
}