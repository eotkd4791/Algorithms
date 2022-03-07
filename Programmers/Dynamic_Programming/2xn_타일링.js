function solution(n) {
    const MOD = 1000000007;
    const dp = Array(60001).fill(0);
    
    for(let i=1; i <= n; i++) {
        if(i <= 2) {
            dp[i] = i;
        } else {
            dp[i] = (dp[i-1] + dp[i-2]) % MOD;   
        }
    }
    return dp[n];
}
