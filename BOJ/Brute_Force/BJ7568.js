const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [n, ...arr] = input;
const N = Number(n);
const info=[];
const rate = new Array(N).fill(0);

arr.forEach(v => {
  const [weight, height] = v.split(' ').map(Number);
  info.push({weight, height});
});

for(let i in info) {
  for(let j in info) {
    if(i===j) rate[i]++;
    else if(info[i].weight < info[j].weight && info[i].height < info[j].height) {
      rate[i]++;
    }
  }
}
const ans = rate.join(' ');
console.log(ans);