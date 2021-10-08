const fs = require('fs');

const getInput = () => {
  const [ndkc, ...dishes] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  return [...ndkc.split(' ').map(Number), dishes.map(Number)];
};

const solution = () => {
  const [n, d, k, c, dishes] = getInput();

  let result = 0;
  let left = 0;
  let right = k;
  let flag = false;
  const table = new Array(d + 1).fill(0);
  dishes.slice(0, k).forEach((v) => table[v]++);
  const set = new Set(dishes.slice(0, k));

  while (1) {
    right < left && (flag = true);
    if (flag && left === 1 && left < right) {
      break;
    }

    result = Math.max(result, set.has(c) ? set.size : set.size + 1);

    table[dishes[left]]--;
    if (table[dishes[left]] === 0) {
      set.delete(dishes[left]);
    }
    table[dishes[right]]++;
    set.add(dishes[right]);

    left = (left + 1) % n;
    right = (right + 1) % n;
  }
  return result;
};

console.log(solution());
