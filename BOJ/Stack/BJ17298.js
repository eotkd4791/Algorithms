const fs = require('fs');
let [n, arr] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

n = Number(n);
arr = arr.split(' ').map(Number);
const ans = new Array(n).fill(-1);
const s = [];

for(let i=0; i<n; i++) {
  while(s.length > 0 && arr[i] > arr[s[s.length-1]]) {
    ans[s.pop()] = arr[i];
  }
  s.push(i);
}
console.log(ans.join(' '));