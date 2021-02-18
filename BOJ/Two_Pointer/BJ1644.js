const N = +require('fs').readFileSync('/dev/stdin').toString();
let primes = new Array(N+1).fill(0).map((v, i) => i);

primes[0] = false;
primes[1] = false;

for(let i=2; i<=N; i++) {
  if(!primes[i]) continue;
  for(let j = i + i; j<=N; j += i) {
    primes[j] = false;
  }
}
primes = primes.filter(v => v);

let left = 0;
let right = 1;
let sum = primes[0];
let answer = 0;

while(left < right) {
  if(sum < N) {
    sum += primes[right++];
  } else {
    if(sum === N) answer++;

    sum -= primes[left++];
  } 
}
console.log(answer);