const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const [A, T, isDaegi] = input.split('\n').map(Number);

const initialBundaegi = '0101';
let bundaegi = '';
let i = 2;
while(bundaegi.length < 10000) {
  bundaegi +=  initialBundaegi + '0'.repeat(i) + '1'.repeat(i++);
}

let num = 0
for(let i=0; i<bundaegi.length; i++) {
  isDaegi == bundaegi[i] && num++;
  if(num === T) { 
    console.log(i % A);
    break;
  }
}