const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const num = Number(input);

let sum=1;
let cnt=1;

while(sum < num) sum += ((cnt++) * 6);

console.log(cnt); 