const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const n = input.length;

function checkPalindrome() {
  const half = Math.floor(n / 2);
  for (let i = 0; i < half; i++) {
    const j = n - i - 1;
    if (i !== j && input[i] !== input[j]) {
      return false;
    }
  }
  return true;
}

function checkSubstring() {
  let left = 0;
  let right = n - 1;
  while (left !== right && input[left] === input[right]) {
    right--;
  }
  return right - left + 1;
}

function solution() {
  if (checkPalindrome()) {
    const answer = checkSubstring();
    return answer === 1 ? -1 : Math.max(answer, n - 1);
  } else {
    return n;
  }
}

console.log(solution());
