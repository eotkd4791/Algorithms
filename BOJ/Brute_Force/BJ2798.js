const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [num, cardStr] = input;
const [N, M] = num.split(' ').map(Number);
const card = cardStr.split(' ').map(Number);

let sum = 0;
let MAX = 0;

for(let i=0; i<N; i++) {
  for(let j=i+1; j<N; j++) {
    for(let k=j+1; k<N; k++) {
      sum = card[i] + card[j] + card[k];
      if(sum <= M) MAX = MAX < sum ? sum : MAX;
    }
  }
}

console.log(MAX);