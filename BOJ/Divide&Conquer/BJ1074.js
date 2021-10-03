const fs = require('fs');

function getInput() {
  return fs.readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);
}

function solution() {
  const [N, r, c] = getInput();
  return recur(0, 0, Math.pow(2, N), 0);

  function recur(sx, sy, len, sum) {
    if (sx === r && sy === c && len === 1) {
      return sum;
    }
    if (sx <= r && r < sx + len / 2 && sy <= c && c < sy + len / 2) {
      return recur(sx, sy, len / 2, sum);
    }
    if (sx <= r && r < sx + len / 2 && sy + len / 2 <= c && c < sy + len) {
      return recur(sx, sy + len / 2, len / 2, sum + Math.pow(len / 2, 2));
    }
    if (sx + len / 2 <= r && r < sx + len && sy <= c && c < sy + len / 2) {
      return recur(sx + len / 2, sy, len / 2, sum + Math.pow(len / 2, 2) * 2);
    }
    if (sx + len / 2 <= r && r < sx + len && sy + len / 2 <= c && c < sy + len) {
      return recur(sx + len / 2, sy + len / 2, len / 2, sum + Math.pow(len / 2, 2) * 3);
    }
  }
}

console.log(solution());
