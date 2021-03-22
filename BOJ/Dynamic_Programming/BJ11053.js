const fs = require('fs');
const [N, A] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(v => {
    const toNumber = Number(v);
    return Number.isNaN(toNumber)
      ? v.split(' ').map(Number)
      : toNumber;
  });


const dp = new Array(N).fill(1);

for(let i=0; i<A.length;i++) {
  for(let j=0; j<i; j++) {
    A[i]>A[j] && (dp[i] = Math.max(dp[j]+1, dp[i]));
  }
}
console.log(Math.max(...dp));