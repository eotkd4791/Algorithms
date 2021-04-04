const fs = require('fs');
let [A, B, C] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split(' ')
  .map(Number);

A = BigInt(A);
B = BigInt(B);
C = BigInt(C);

const recur = N => {
  if(N <= 2) return ((A % C) ** BigInt(N)) % C;

  const half = N / BigInt(2);
  const result = recur(half) % C;

  return Boolean(N % BigInt(2))
    ? (((result * result) % C) * (A % C)) % C 
    : (result * result) % C;
};

console.log(recur(B).toString());