const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
input.pop();

input.forEach((v, i) => {
  let cnt = 0;
  for(let j = v+ 1; j <= v * 2; j++) {
    const sqrt = Math.sqrt(j);
    if(j === 1) continue;

    let isPrime = true;
    for(let k = 2; k <= sqrt; k++) {
      if(j!==k && j % k === 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) cnt++;
  }
  console.log(cnt);
});