const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('');

const croatianAlphbetTable = {
  'c=': true,
  'c-': true,
  'dz=': true,
  'd-': true,
  'lj': true,
  'nj': true,
  's=': true,
  'z=': true
};

let result = 0;
let i = 0;

while(i < input.length) {
  let tmpStr = input[i];
  let isMatching = false;

  for(let j = 1; j < 3; j++) {
    tmpStr += input[i + j]
    if(croatianAlphbetTable[tmpStr]) {
      isMatching = true;
      i += j + 1;
      break;
    }
  }
  if(!isMatching) i++;
  result++;
}

console.log(result);