const fs = require('fs');
const [T, ...args] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

function underTen(num) {
  return num < 10 ? '0' + num : num.toString();
}

const arr = args.reduce((acc, cur) => {
  const curArr = cur.split(' ').map(Number);
  acc.push(curArr);
  return acc;
}, []);

arr.forEach((info, i) => {
  const [H, W, N] = info;
  const floor = N % H;
  const room = Math.floor(N / H);

  if(floor) console.log((floor).toString().concat(underTen(room+1)));
  else console.log(H.toString().concat(underTen(room)));
});