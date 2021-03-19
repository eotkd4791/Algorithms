const fs = require('fs');
const N = +fs.readFileSync('/dev/stdin').toString().trim();
const MOD = 1_000_000_000;

const dp = JSON.parse(
  JSON.stringify(
    new Array(101).fill(
      new Array(11).fill(0)
    )
  )
);

for(let i=1; i<=9; i++) {
  dp[1][i] = 1;
}

for(let i=2; i<=100; i++) {
  for(let j=0; j<=9; j++) {
    dp[i][j] = j === 0 
      ? dp[i-1][1]
      : (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
  }
}

const answer = dp[N].reduce((acc, cur) => (acc+cur)%MOD);
console.log(answer%MOD);