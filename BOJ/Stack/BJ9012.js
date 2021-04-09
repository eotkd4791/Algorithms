const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const T = +input.shift();

for(const br of input) {
  const stack = [];
  for(let i=0; i<br.length; i++) {
    if(br[i] === '(' ) stack.push('(');
    else {
      if(stack.length > 0) stack.pop();
      else {
        stack.push('(');
        break;
      }  
    }
  } 
  console.log(stack.length === 0 ? 'YES' : 'NO');
}