const [T, ...testCases] = require('fs')
.readFileSync('/dev/stdin')
.toString()
.split('\n')
.map(Number);

const dp = [1,1,1];

for(let i=3; i <= 100; i++) {
  dp[i] = dp[i-3] + dp[i-2];
}

for(let i=0; i<T; i++) {
  console.log(dp[testCases[i]-1]);
}