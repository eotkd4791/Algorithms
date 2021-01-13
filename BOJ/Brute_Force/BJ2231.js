const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const N = parseInt(input);
let flag = false;

for(let i=1; i<=N; i++) {
  let sum=0;
  let temp = i;

  while(temp>0) {
    sum += temp % 10;
    temp = Math.floor(temp/10);
  }
  if(N === sum + i) {
    flag = true;
    console.log(i);
    break;
  }
}
if(!flag) console.log(0);