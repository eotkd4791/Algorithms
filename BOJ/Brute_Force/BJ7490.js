const fs = require('fs');
const [, ...tc] = fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);

function solution() {
  const answer = [];
  for(const N of tc) {
    recur(1, N, '1');
    answer.push('\n')
  }
  return answer.join('');

  function recur(cnt, n, str) {
    if(cnt === n) {
      isZero(str.split(' ').join('')) && answer.push(`${str}\n`);
      return;
    }
    recur(cnt + 1, n, `${str} ${cnt + 1}`);
    recur(cnt + 1, n, `${str}+${cnt + 1}`);
    recur(cnt + 1, n, `${str}-${cnt + 1}`);
  }

  function isZero(str) {
    return eval(str) === 0;
  }
}

console.log(solution());