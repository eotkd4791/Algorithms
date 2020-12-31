const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

const num1 = input[0].split('').reverse().join('');
const num2 = input[1].split('').reverse().join('');

const answer = Number(num1) > Number(num2) ? num1 : num2;
console.log(answer);