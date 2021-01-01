const fs = require('fs');
const [cnt, ...input] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

let maximumGroupWordCnt = Number(cnt);

for(const i in input) {
  const check = {};
  let latestStr;
  for(const str of input[i]) {
    if(check[str]) {
      if(latestStr!==str) {
        maximumGroupWordCnt--;
        break;
      }
    } else {
      check[str] = true;
    }
    latestStr = str;
  }
}
console.log(maximumGroupWordCnt);