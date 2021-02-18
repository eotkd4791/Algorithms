const input = require('fs')
  .readFileSync('/dev/stdin')
  .toString()
  .split(' ')
  .join('\n')
  .split('\n')
  .reduce((acc,cur) => acc.concat(cur), [])
  .map(Number);
  
let [N, K, ...coin] = input;
  
let whichCoin = 0;
let cntCoin = 0;

coin.some((v, i) => {
  whichCoin = i;
  return v > K;
});

whichCoin--;

while(K>0) {
  cntCoin += Math.floor(K/coin[whichCoin]);
  K %= coin[whichCoin];
  whichCoin--;
}
console.log(cntCoin);