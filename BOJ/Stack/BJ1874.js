const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

input.shift();
let next = 1;
let answer='';
const s = [];

for(const num of input) {
  if(s.length === 0 || s[s.length-1] <= num) {
    while(next <= num) {
      s.push(next++);
      answer+= '+\n';
    }
    s.pop();
    answer+='-\n';
  } else if(s[s.length-1] > num) {
    answer = 'NO';
    break;
  }
}
console.log(answer);