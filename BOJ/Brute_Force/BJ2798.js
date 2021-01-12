const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [num, cardStr] = input;
const [N, M] = num.split(' ').map(Number);
const card = cardStr.split(' ').map(Number);

let sum = 0;
let MAX = 0;

for(let i=0; i<N; i++) {
  if(sum + card[i]>M) continue;
  sum += card[i];
  for(let j=i+1; j<N; j++) {
    if(sum + card[j] > M) continue;
    sum+=card[j];
    for(let k=j+1; k<N; k++) {
      if(sum+card[k]>M) continue;
      sum+=card[k];
      MAX = MAX < sum ? sum : MAX;
      sum-=card[k]
    }
    sum-=card[j];
  }
  sum -= card[i];
}

console.log(MAX);