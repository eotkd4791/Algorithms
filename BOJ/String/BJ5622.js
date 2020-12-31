const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const time = [3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10];

let sum = input
  .split('')
  .reduce((acc, value) => acc + time[value.charCodeAt() - 65], 0);

console.log(sum);