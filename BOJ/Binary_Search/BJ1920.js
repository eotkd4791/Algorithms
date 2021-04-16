const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [N, A, M, Q] = input.map(v => {
  const toNum = Number(v);
  return Number.isNaN(toNum) 
    ? v.split(' ').map(Number)
    : toNum;
})

A.sort((a, b) => a - b);

for(let i=0; i<M; i++) {
  let left = 0;
  let right = N - 1;
  let answer = 0;

  while(left <= right) {
    const mid = Math.floor((left + right) / 2);
    if(A[mid] > Q[i]) {
      right = mid - 1;
    } else if(A[mid] < Q[i]) {
      left = mid + 1;
    } else {
      answer = 1;
      break;
    } 
  }
  console.log(answer);
}