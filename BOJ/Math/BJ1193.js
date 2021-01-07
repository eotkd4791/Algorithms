const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
let num = Number(input);

let cnt=0;
while(num > 0) {
  cnt++;
  num -= cnt;
}

if(cnt % 2) console.log(`${1 + (-num)}/${cnt + num}`);
else console.log(`${cnt + num}/${1 + (-num)}`);