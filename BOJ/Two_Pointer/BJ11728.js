const fs = require('fs');

function getInput() {
  const [, A, B] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  return [A.split(' ').map(Number), B.split(' ').map(Number)];
}

function solution() {
  const [A, B] = getInput();
  return A.concat(B)
    .sort((a, b) => a - b)
    .join(' ');
}

console.log(solution());
