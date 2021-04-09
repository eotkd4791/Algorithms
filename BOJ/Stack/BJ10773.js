const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n')
  .map(Number);

const K = input.shift();
const stack =[];

for(const num of input) {
  num === 0 
    ? stack.pop()
    : stack.push(num);
}

let sum = 0;
while(stack.length > 0) sum += stack.pop();

console.log(sum);