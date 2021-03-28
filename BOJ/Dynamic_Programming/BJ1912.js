const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

let [N, arr] = input.map(v => {
  const toNum = Number(v);
  return Number.isNaN(toNum)
    ? v.split(' ').map(Number)
    : toNum;
});

arr = Array.isArray(arr) ? arr : [arr];

const dp = new Array(N).fill(0);
dp[0] = arr[0];

for(let i=1; i<N; i++) {
  dp[i] = Math.max(arr[i], dp[i-1] + arr[i]);
}

console.log(Math.max(...dp));