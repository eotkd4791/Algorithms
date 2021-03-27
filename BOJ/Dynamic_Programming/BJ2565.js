const fs = require('fs');
const [N, ...lines] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(v => {
    const toNum = Number(v);
    return Number.isNaN(toNum) 
      ? v.split(' ').map(Number)
      : toNum;
  });

const dp = new Array(N).fill(1);

lines.sort((a, b) => a[0] - b[0]);

for(let i=0; i<N; i++) {
  for(let j=0; j<i; j++) {
    if(lines[i][1] > lines[j][1]) {
      dp[i] = Math.max(dp[i], dp[j] + 1);
    }
  }
}

const lineCntNotToRemove = Math.max(...dp);

console.log(N - lineCntNotToRemove);