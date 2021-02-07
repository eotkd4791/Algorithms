const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [T, num] = input
const N = Number(T);
const arr = num.split(' ').map(Number);

let cnt = 0;
for(let i=0; i<N; i++) {
  let curValue = arr[i];

  if(curValue === 1) continue;

  let isPrime = true;
  for(let j=2; j<curValue; j++) {
    if(j === curValue) continue;
    if(curValue % j === 0) {
      isPrime = false;
      break;
    }
  }
  if(isPrime) cnt++;
}
console.log(cnt);