const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [testCase, ...evens] = input.map(Number);

const MAX = 10000;
const sieve = new Array(MAX + 1).fill(false);

for(let i=2; i<=MAX; i++) {
  let isPrime = true;
  const sqrt = Math.floor(Math.sqrt(i));

  for(let j=2; j<=sqrt; j++) {
    if(i % j === 0) {
      isPrime = false;
      break;
    }
  }
  if(isPrime) sieve[i] = true;
}

for(let i=0; i<testCase; i++) {
  let firstPrime;
  let secondPrime;
  const half = evens[i]/2;

  for(let j=2; j<=half; j++) {
    if(sieve[j] && sieve[evens[i] - j]) {
      firstPrime = Math.min(j ,evens[i] - j);
      secondPrime = Math.max(j ,evens[i] - j);
    }
  }
  console.log(firstPrime + ' ' + secondPrime);
}