const fs = require('fs');

function input() {
  const [nm, mArr] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  const [n] = nm.split(' ').map(Number);
  const m = mArr?.split(' ').map(Number) || [];
  return [n, m];
}

function solution() {
  let result = 0;

  const [n, m] = input();
  const check = arrForCheckIfShoudContain();

  recur(0, 0);

  return result;

  function recur(pickedCnt, cnt) {
    if (pickedCnt === n) {
      cnt === m.length && result++;
      return;
    }

    for (let i = 0; i < 10; i++) {
      if (check[i]) {
        check[i] = false;
        recur(pickedCnt + 1, cnt + 1);
        check[i] = true;
      } else {
        recur(pickedCnt + 1, cnt);
      }
    }
  }

  function arrForCheckIfShoudContain() {
    const check = new Array(10).fill(false);

    m.forEach((value) => (check[value] = true));

    return check;
  }
}

console.log(solution());
