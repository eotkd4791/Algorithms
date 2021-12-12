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

function checkAllSameLetters() {
  const set = new Set();
  for (const s of input) {
    set.add(s);
  }
  return set.size === 1;
}

function solution() {
  if (checkAllSameLetters()) {
    return -1;
  }
  return checkPalindrome() ? n - 1 : n;
}

console.log(solution());
