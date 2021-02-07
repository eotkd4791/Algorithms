const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);
const [M, N] = input;

for(let i=M; i<=N; i++) {
  const sqrt = Math.sqrt(i);
  if(i === 1) continue;

  let isPrime = true;
  for(let j=2; j<=sqrt; j++) {
    if(i!==j && i % j === 0) {
      isPrime = false;
      break;
    }
  }
  if(isPrime) console.log(i);
}