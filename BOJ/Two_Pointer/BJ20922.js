const fs = require('fs');

const getInput = () => {
  const [nk, arr] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  return [...nk.split(' ').map(Number), arr.split(' ').map(Number)];
};

const solution = () => {
  const [N, K, arr] = getInput();
  const cnt = new Array(100_001).fill(0);
  let result = 1;
  let left = 0;
  let right = 0;

  while (left < N && right < N) {
    if (cnt[arr[right]] === K) {
      cnt[arr[left++]]--;
    } else {
      result = Math.max(result, right - left + 1);
      cnt[arr[right++]]++;
    }
  }
  return result;
};

console.log(solution());
