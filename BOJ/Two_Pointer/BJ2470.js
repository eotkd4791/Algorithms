const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, liquid] = input.map(v => {
  const valueToNumber = Number(v);

  if(Number.isNaN(valueToNumber)) 
    return v.split(' ').map(Number);
  return valueToNumber;
});
liquid.sort((a, b) => a - b);

let left = 0;
let right = liquid.length - 1;
let NumCloseToZero = Infinity;
let answer = [];

while(left < right) {
  const sum = liquid[left] + liquid[right];

  if(Math.abs(sum) < Math.abs(NumCloseToZero)) {
    NumCloseToZero = sum;
    answer[0] = liquid[left];
    answer[1] = liquid[right];
  }
  if(sum < 0) left++;
  else right--;
}
console.log(...answer.sort((a,b) => a - b));