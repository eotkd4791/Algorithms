const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [n, c] = input
  .shift()
  .split(' ')
  .map(Number);

const x = input
  .map(Number)
  .sort((a, b) => a - b);

let left = 0;
let right = 1_000_000_000;
let ans = 0;

while(left <= right) {
  const mid = Math.floor((left + right) / 2);

  let cnt = c - 1;
  let prev = x[0];
  for(let i = 1; i < n; i++) {
    if(x[i] - prev >= mid) {
      cnt--;
      prev = x[i];
    }
  }
  if(cnt > 0) {
    right = mid - 1;
  } else {
    left = mid + 1;
    ans = mid;
  }
}
console.log(ans);