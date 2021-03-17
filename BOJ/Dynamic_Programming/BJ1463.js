const fs = require('fs');
const N = +fs.readFileSync('/dev/stdin').toString();

const dp = new Array(N+1).fill(0);

for(let i=2; i<=N; i++) {
  dp[i] = dp[i-1] + 1;
  
  if(i % 3 === 0) {
    dp[i] = Math.min(dp[i / 3] + 1, dp[i]);  
  }
  if(i % 2 ===0) {
    dp[i] = Math.min(dp[i / 2] + 1, dp[i]);
  }
}
console.log(dp[N]);
