const fs = require('fs');
let [A, B] = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

const lenDiff = A.length - B.length;
const dummyZero = '0'.repeat(Math.abs(lenDiff));

if(lenDiff > 0) B = dummyZero.concat(B);
else if(lenDiff < 0) A = dummyZero.concat(A);

let res = '';
let isOverTen = false;

for(let i=A.length - 1; i>=0; i--) {
  const numA = Number(A[i]);
  const numB = Number(B[i]);

  let sum  = numA + numB;
  
  if(isOverTen) {
    sum++;
    isOverTen = false;
  }
  if(sum >= 10) {
    isOverTen = true;
    sum -= 10;
  }
  res = sum + res;
}
if(isOverTen) res ='1'.concat(res);

console.log(res);