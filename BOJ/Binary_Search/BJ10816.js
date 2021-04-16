const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const n = Number(input[0]);
const vals = input[1].split(' ').map(Number).sort((a, b) => a - b);
const m = Number(input[2]);
const queries = input[3].split(' ').map(Number);


function lowerBound(target) {
  let from = 0;
  let to = n;

  while(from < to) {
    const mid = Math.floor((from + to) / 2);
    
    vals[mid] < target
      ? from = mid + 1
      : to = mid;
  }
  return to;
}

function upperBound(target) {
  let from = 0;
  let to = n;
  
  while(from < to) {
    const mid = Math.floor((from + to) / 2);

    vals[mid] <= target
      ? from = mid + 1
      : to = mid;
  }
  return to;
}

let ans = '';
for(const q of queries) {
  ans += (upperBound(q) - lowerBound(q)).toString().concat(' ');
}
console.log(ans);