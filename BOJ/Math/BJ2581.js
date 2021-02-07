const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
const [M, N] = input;

const primeArr = [];

for(let i=M; i<=N; i++) {
  const sqrt = Math.sqrt(i);
  if(i === 1) continue;

  let isPrime = true;
  for(let j=2; j<=sqrt+10; j++) {
    if(i!==j && i % j === 0) {
      isPrime = false;
      break;
    }
  }
  if(isPrime) primeArr.push(i);
}

if(primeArr.length > 0) {
  const sum = primeArr.reduce((acc, cur) => acc + cur, 0);
  console.log(sum);
  console.log(primeArr[0]);
} else {
  console.log(-1);
}