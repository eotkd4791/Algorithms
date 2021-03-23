const fs = require('fs');
const [N, A] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(v => {
    const toNum = Number(v);
    return Number.isNaN(toNum) 
      ? v.split(' ').map(Number) 
      : toNum;
  });

let ans = 0;
const dp = JSON.parse(
  JSON.stringify(
    new Array(N).fill(
      new Array(2).fill(1)
    )
  )
);

for(let i=0; i<N; i++) {
  for(let j=0; j<i; j++) {
    if(A[i] > A[j]) {
      dp[i][0] = Math.max(dp[i][0], dp[j][0] + 1);
    }
  }
}

for(let i=N-1; i>=0; i--) {
  for(let k=N-1; k>i; k--) {
    if(A[i] > A[k]) {
      dp[i][1] = Math.max(dp[i][1], dp[k][1] + 1);
    }
  }
}

for(let i=0; i<N; i++) {
  ans = Math.max(ans, dp[i][0] + dp[i][1]);
}

console.log(ans - 1);