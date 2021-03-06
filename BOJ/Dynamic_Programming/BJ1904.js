const input = require('fs').readFileSync('/dev/stdin').toString();
const N = parseInt(input);

const MAX = 1000000 + 1;
const MOD = 15746;

const dp = new Array(MAX).fill(0);
dp[1] = 1;
dp[2] = 2;

for(let i=3; i<=N; i++) {
  dp[i] = (dp[i-1] % MOD + dp[i-2] % MOD) % MOD;
}

console.log(dp[N]);