const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

input.pop();

for(const str of input) {
  const stack = [];
  let isPair = true;
  for(const letter of str) {
    if(letter === '(' || letter === '[') {
      stack.push(letter);
    } else if(letter === ')') {
      if(stack.length > 0 && stack[stack.length-1] === '(') {
        stack.pop();
      } else {
        isPair = false;
        break;
      }
    } else if(letter === ']') {
      if(stack.length > 0 && stack[stack.length-1] === '[') {
        stack.pop();
      } else {
        isPair = false;
        break;
      }
    }
  }
  console.log(isPair && stack.length === 0 ? 'yes' : 'no');
}