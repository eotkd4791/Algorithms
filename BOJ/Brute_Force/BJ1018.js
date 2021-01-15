const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const [XY, ...field] = input;
const [N, M] = XY.split(' ').map(Number);

const WW = JSON.parse(JSON.stringify(new Array(8).fill(new Array(8).fill('W'))));
const BB = JSON.parse(JSON.stringify(new Array(8).fill(new Array(8).fill('B'))));

let MIN = Infinity;

WW.forEach((arr, i) => {
  arr.forEach((v, j) => {
    if((i + j) % 2) {
      WW[i][j] = 'W';
      BB[i][j] = 'B';
    } else { 
      WW[i][j] = 'B';
      BB[i][j] = 'W';
    }
  });
});

for(let i=0; i<N; i++) {
  for(let j=0; j<M; j++) {
    if(i+8 <= N && j+8 <= M) {
      let wcnt = 0;
      let bcnt = 0;
      for(let k=0; k<8; k++) {
        for(let l=0; l<8; l++) {
          if(field[i+k][j+l] !== WW[k][l]) {
            wcnt++;
          }
          if(field[i+k][j+l] !== BB[k][l]) {
            bcnt++;
          }
        }
      }
      MIN = Math.min(MIN, bcnt, wcnt);
    }
  }
}
console.log(MIN);