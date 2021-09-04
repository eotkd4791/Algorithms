const fs = require("fs");

const input = () => {
  const [n, ...table] = fs
    .readFileSync("/dev/stdin")
    .toString()
    .trim()
    .split("\n");

  const N = +n;
  const T = new Array(N + 1).fill(0);
  const P = new Array(N + 1).fill(0);

  table.forEach((pair, i) => {
    const [t, p] = pair.split(" ").map(Number);
    T[i + 1] = t;
    P[i + 1] = p;
  });
  return { N, T, P };
};

const solution = () => {
  const { N, T, P } = input();
  const dp = new Array(N + 2).fill(0);

  for (let i = N; i >= 1; i--) {
    dp[i] =
      i + T[i] > N + 1 ? dp[i + 1] : Math.max(dp[i + 1], dp[i + T[i]] + P[i]);
  }
  return dp[1];
};

console.log(solution());
