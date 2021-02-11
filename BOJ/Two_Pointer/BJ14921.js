const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, A] = input.map(v => {
  const valueToNum = Number(v);
  if(Number.isNaN(valueToNum)) { 
    return v.split(' ').map(Number);
  } else {
    return valueToNum;
  }
});

let answer = Infinity;
let left = 0;
let right = A.length - 1;

while(left < right) {
  const sum = A[left] + A[right];

  if(sum < 0) left++;
  else right--;

  if(Math.abs(answer) > Math.abs(sum))
    answer = sum;
}
console.log(answer);