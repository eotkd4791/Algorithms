#include <iostream>
#define endl '\n'
using namespace std;

int n,m,a[1001],b;
const long long INF = 1000000000;
bool over9;

int gcd(int x, int y) {
    if(y==0) return x;
    return gcd(y, x%y);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a[i];
    }
    
    long long ans = 1;
    
    cin >> m;
    for(int j=0; j<m; j++) {
        cin >> b;
        
        for(int i=0; i<n; i++) {
            if(a[i] != 1) {
                int temp = gcd(a[i], b);
                ans *= temp;
                
                if(ans >= INF) {
                    over9 = true;
                    ans %= INF;
                }
                a[i] /= temp;
                b /= temp;
                
                if(b==1) break;
            }
        }
    }
    
    
    if(over9) {
        string str = to_string(ans);
        int loop = 9 - (int) str.size();
        while(loop--) cout << "0";
    }
    cout << ans << endl;
    return 0;
}
