const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const [N, S, ...arr] = input[0].split(' ').concat(input[1].split(' ')).map(Number);

let left = 0;
let right = 0;
let answer = Infinity;
let len = 1;
let sum = arr[0];

while(right < N) {
  if(sum >= S) {
    answer = Math.min(answer, len);
    sum -= arr[left++];
    len--;
  } else {
    sum += arr[++right];
    len++;
  }
}

console.log(answer === Infinity ? 0 : answer);