#include <string>
#include <vector>

using namespace std;

const int MOD = 1000000007;
int dp[60001];

int solution(int n) {
    if(n <= 2) {
        return dp[n] = n;
    }
    if(dp[n] > 0) {
        return dp[n];
    }
    return dp[n] = (solution(n-2) + solution(n-1)) % MOD;
}
