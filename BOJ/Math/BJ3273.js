const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, a, x] = input.map(v => {
  const valueToNum = Number(v);
  if(Number.isNaN(valueToNum)) {
    return v.split(' ').map(Number);
  }
  return valueToNum;
});

const check = {};
let left = 0;
let right = a.length-1;
let answer = 0;

while(left < right) {
  if(a[left] + a[right] === x) {
    answer++;
  } else {
    if(check.hasOwnProperty(x-a[left])) {
      answer++;
      delete check[x-a[left]];
    } else {
      check[a[left]] = true;
    }
    if(check.hasOwnProperty([x-a[right]])) {
      answer++;
      delete check[x-a[right]];
    } else {
      check[a[right]] = true;
    }
  } 
  left++;
  right--;
}
console.log(answer);