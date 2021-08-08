const fs = require('fs');

function input() {
  const [n, ...field] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  return {
    n: +n, 
    field: field.map(col => col.split(' ').map(Number))
  }
}

function solution() {
  const { n, field } = input();
  return recur(0, 0, n);

  function recur(sx, sy, size) {
    if(size === 1) {
      return field[sx][sy];
    }

    const half = Math.floor(size / 2);
    return [
      recur(sx, sy, half),
      recur(sx + half, sy, half),
      recur(sx, sy + half, half),
      recur(sx + half, sy + half, half)
    ].sort((a, b) => b - a)[1];
  };
}

console.log(solution());