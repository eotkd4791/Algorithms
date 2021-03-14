const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const [N, ...costs] = input.map(v => {
  const isNumber = Number(v);
  if(Number.isNaN(isNumber)) {
    return v.split(' ').map(Number);
  }
  return isNumber;
});

const est = JSON.parse(
  JSON.stringify(
    new Array(N).fill(
      new Array(3).fill(0)
    )
  )
);

est[0][0] = costs[0][0];
est[0][1] = costs[0][1];
est[0][2] = costs[0][2];

for(let i=1; i<N; i++) {
  for(let j=0; j<3; j++) {
    if(j===0) {
      est[i][j] = costs[i][j] + Math.min(est[i-1][1], est[i-1][2]);
    } else if(j===1) {
      est[i][j] = costs[i][j] + Math.min(est[i-1][0], est[i-1][2]);
    } else {
      est[i][j] = costs[i][j] + Math.min(est[i-1][0], est[i-1][1]);
    }
  }
}
console.log(Math.min(...est[N-1]));