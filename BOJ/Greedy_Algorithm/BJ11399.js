const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, pTemp] = input.map(v => {
  const valueToNumber = Number(v);
  if(Number.isNaN(valueToNumber)) {
    return v.split(' ').map(Number).sort((a, b) => a - b);
  }
  return valueToNumber;
});

if(Array.isArray(pTemp)) 
  P = pTemp;
else P = [pTemp];

let ans = P[0];
for(let i=1; i<N; i++) {
  P[i] += P[i-1];
  ans += P[i];
}

console.log(ans);