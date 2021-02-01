const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [T, ...testCases] = input;

const apt = JSON.parse(JSON.stringify(new Array(16).fill(new Array(16).fill(0))));

for(let i=0; i<=14; i++) {
  let sum = 0;
  for(let j=1; j<=14; j++) {
    if(i===0) {
      apt[i][j] = j;
    } else {
      sum += apt[i-1][j];
      apt[i][j] = sum;
    }
  }
}

for(let i=0; i<testCases.length; i+=2) {
  const k = Number(testCases[i]);
  const n = Number(testCases[i+1]);
  console.log(apt[k][n]);
}