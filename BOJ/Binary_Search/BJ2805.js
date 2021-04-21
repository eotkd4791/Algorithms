const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [_, M] = input.shift().split(' ').map(Number);
const tree = input[0].split(' ').map(BigInt);

let ans = 0;
let left = BigInt(0);
let right = BigInt(2_000_000_000);

while(left<=right) {
  const mid = ((left + right) / BigInt(2));

  let sum = BigInt(0);
  const result = tree.some(h => {
    sum += h > mid ? h - mid : BigInt(0);
    return sum >= M;
  });
  
  if(result) {
    left = mid + BigInt(1);
    ans = mid;
  } else {
    right = mid - BigInt(1);
  }
}
console.log(ans.toString());