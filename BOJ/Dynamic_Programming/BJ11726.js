const fs = require('fs');
const MOD = 10_007;

const solution = () => {
  const N = +fs.readFileSync('/dev/stdin').toString();
  const dp = new Array(N + 1).fill(0);

  return recur(N);

  function recur(n) {
    if (n <= 2) {
      return (dp[n] = n);
    }

    if (dp[n] > 0) {
      return dp[n];
    }

    return (dp[n] = ((recur(n - 1) % MOD) + (recur(n - 2) % MOD)) % MOD);
  }
};

console.log(solution());
