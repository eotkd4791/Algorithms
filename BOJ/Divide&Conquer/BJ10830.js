const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

let [N, B] = input
  .shift()
  .split(' ')
  .map(Number);

B = BigInt(B);
const MOD = 1000;

const A = input.reduce((acc, cur) => {
  const toNum = cur
    .split(' ')
    .map(Number);

  acc.push(toNum);
  return acc;
}, []);

const recur = cur => {
  if(cur === BigInt(1)) return A;

  const half = recur(cur / BigInt(2));
  const multiplied = multiplyMatrix(half, half);
  return cur % BigInt(2) ? multiplyMatrix(A, multiplied) : multiplied;
};

const multiplyMatrix = (a, b) => {
  const temp = JSON.parse(JSON.stringify(new Array(N).fill(new Array(N).fill(0))));

  for(let i=0; i<N; i++) {
    for(let j=0; j<N; j++) {
      for(let k=0; k<N; k++) { 
        temp[i][j] += a[i][k] * b[k][j] % MOD;
        temp[i][j] %= MOD;
      }
    }
  }
  return temp;
};

const result = recur(B);
const answer = result.map(v => v.map(w => w % MOD).join(' '));
for(ans of answer) { console.log(ans); }