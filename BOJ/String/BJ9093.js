const fs = require('fs');
const [, ...inputs] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const answer = inputs
  .map((input) =>
    input
      .split(' ')
      .map((word) => word.split('').reverse().join(''))
      .join(' ')
  )
  .join('\n');
console.log(answer);
