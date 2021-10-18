const fs = require('fs');

function solution() {
  const [, ...inputs] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  let result = '';

  for (let testCase = 1; testCase < inputs.length; testCase += 2) {
    const arr = inputs[testCase].split(' ').map(Number);
    let max = -1_000_001;
    let min = 1_000_001;
    for (const num of arr) {
      min = Math.min(num, min);
      max = Math.max(num, max);
    }
    result += `${min} ${max}\n`;
  }
  return result;
}
console.log(solution());
