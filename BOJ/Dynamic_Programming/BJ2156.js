const fs = require('fs');
let [n, ...wines] = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);
wines = [0].concat(wines);
  
const dp = new Array(n+1).fill(0);

dp[1] = wines[1];
dp[2] = dp[1] + wines[2];

for(let i=3; i<=n; i++) {
  dp[i] = Math.max(
    dp[i-2] + wines[i],
    dp[i-3] + wines[i-1] + wines[i],
    dp[i-1]
  );
}

console.log(dp[n]);