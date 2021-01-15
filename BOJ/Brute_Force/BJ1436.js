const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

const N = Number(input);
let termNum = 665;
let cnt=0;

while(1) {
  if(cnt===N) break;
  termNum++;

  const termStr = termNum.toString();
  if(/666/g.test(termStr)) {
    cnt++;
  }
}
console.log(termNum);