const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

function solution() {
  let l = 0;
  let r = 0;
  let total = 0;
  let result = 0;

  for(const bracket of input) {
    if(bracket === '(') {
      l++;
      total++;
    } else {
      r++;
      total--;
    }
    if(total <= 1) {
      l = 0;
    }
    if(total < 0) {
      result = r;
      break;
    }
  }
  total > 0 && (result = l);
  return result;
}

console.log(solution());