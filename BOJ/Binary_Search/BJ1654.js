const fs = require('fs');
let lans = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [_, n] = lans
.shift()
.split(' ')
.map(Number);

lans = lans.map(Number);

let left = BigInt(1);
let right = BigInt(1) << BigInt(31);
let ans = BigInt(0);

const canBeMore = length => {
  let result = BigInt(0);
  for(const aLan of lans) {
    result += BigInt(aLan) / length;
  }
  return n <=result;
};

while(left <= right) {
  const mid = (left + right) / BigInt(2);

  if(canBeMore(mid)) {
    left = mid + BigInt(1);
    ans = mid;
  } else {
    right = mid - BigInt(1);
  }
}
console.log(ans.toString());