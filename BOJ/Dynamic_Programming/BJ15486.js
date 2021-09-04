const fs = require('fs');
const [n, ...t] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

function solution() {
  const N = +n;
  const table = t.map((pair) => pair.split(' ').map(Number));
  const dp = new Array(N + 1).fill(0);

  for (let i = N - 1; i >= 0; i--) {
    dp[i] = table[i][0] + i >= N + 1 ? dp[i + 1] : Math.max(dp[i + 1], table[i][1] + dp[i + table[i][0]]);
  }
  return dp[0];
}

console.log(solution());
