const input = require('fs').readFileSync('/dev/stdin').toString().split('\n');

const [, distance, cost] = input.map((str) => {
  if(Number.isNaN(+str)) {
    return str.split(' ').map(v => BigInt(v));
  }
  return [+str];
});

let minSumCost = BigInt(0);
for(let i=0; i<distance.length; i++) {
  if(cost[i] < cost[i+1]) {
    cost[i+1] = cost[i];
  }
  minSumCost += (cost[i] * distance[i]);
}
console.log(minSumCost.toString());