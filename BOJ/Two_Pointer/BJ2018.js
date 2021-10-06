const fs = require('fs');
const getInput = () => +fs.readFileSync('/dev/stdin').toString().trim();

const solution = () => {
  const N = getInput();

  let result = 0;
  let left = 0;
  let right = 0;
  let sum = 0;

  while (left <= right && left <= N) {
    if (sum < N) {
      right++;
      sum += right;
    } else {
      sum === N && result++;
      left++;
      sum -= left;
    }
  }
  return result;
};

console.log(solution());
