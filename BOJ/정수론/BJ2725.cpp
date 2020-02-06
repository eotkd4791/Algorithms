#include <iostream>
#define INF 1000
using namespace std;

int C, N;
int dp[INF + 1];

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    dp[1] = 3;

    for(int i = 2; i<=1000; i++) {
        int cnt = 0;
        for(int j=1; j<=i; j++) {
            if(gcd(i,j)==1) {
                cnt++;
            }
        }
        dp[i] = dp[i-1] + cnt;
    }
    cin >> C;
    while(C--) {
        cin >> N;
        cout << dp[N] * 2 - 3 << '\n';
    }
    
    return 0;
}
