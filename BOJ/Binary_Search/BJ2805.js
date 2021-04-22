const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [_, M] = input.shift().split(' ').map(Number);
const tree = input[0].split(' ').map(Number);

let ans = 0;
let left =0;
let right = 2_000_000_000;

while(left<=right) {
  const mid = Math.floor((left + right) / 2);

  let sum =0;
  const result = tree.some(h => {
    sum += h > mid ? h - mid : 0;
    return sum >= M;
  });
  
  if(result) {
    left = mid + 1;
    ans = mid;
  } else {
    right = mid -1;
  }
}
console.log(ans);