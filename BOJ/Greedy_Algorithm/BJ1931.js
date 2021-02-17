const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, ...meetings] = input.map(v => {
  const valueToNum = Number(v);
  if(Number.isNaN(valueToNum)) {
    return v.split(' ').reduce((acc, cur) => acc.concat(Number(cur)), []);
  } else {
    return valueToNum;
  }
});

meetings.sort((a,b) => {
  const endDiff = a[1] - b[1];

  if(endDiff === 0)
    return a[0] - b[0];

  else 
    return endDiff;
});

let pickedRoom = meetings[0][1];
let roomCnt = 1;

for(let i=1; i<N; i++) {
  if(pickedRoom <= meetings[i][0]) {
    pickedRoom = meetings[i][1];
    roomCnt++;
  }
}

console.log(roomCnt);