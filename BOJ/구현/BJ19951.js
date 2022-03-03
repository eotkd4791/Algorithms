const fs = require('fs');
let [nm, h, ...o] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

function input() {
  n = nm.split(' ').map(Number)[0];
  m = nm.split(' ').map(Number)[1];
  const height = h.split(' ').map(Number);
  order = o.map((ord) => ord.split(' ').map(Number));
  return [n, m, height, order];
}

function solution() {
  const [n, _, height, order] = input();

  for (const [a, b, k] of order) {
    sum[a - 1] += k;
    sum[b] -= k;
  }

  for (let i = 1; i < n; i++) {
    sum[i] = sum[i - 1] + sum[i];
  }

  for (let i = 0; i < n; i++) {
    height[i] += sum[i];
  }

  return height.join(' ');
}

console.log(solution());
