const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');
const arr = input[1].toString().split('');
const sum = arr.map(v => Number(v)).reduce((acc, cur) => acc + cur, 0);

console.log(sum);