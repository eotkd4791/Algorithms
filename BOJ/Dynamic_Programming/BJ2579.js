const fs = require('fs');
const input = fs
.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

let [N, ...stairs] = input;
stairs = [0, ...stairs];

const dp = new Array(N+1).fill(0);

dp[1] = stairs[1];
dp[2] = dp[1] + stairs[2];

for (let i = 3; i <= N; i++) {
  dp[i] = Math.max(
    dp[i - 2] + stairs[i], 
    dp[i-3]+stairs[i-1]+stairs[i],
    stairs[i - 1] + stairs[i]
  );
}
console.log(dp[N]);