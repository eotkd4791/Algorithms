const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const INF = 987654321;
let min = INF;
let max = -INF;

function countOdds(str) {
  let result = 0;
  for (const s of str) {
    result += Number(s) % 2;
  }
  return result;
}

function splitThreeStr(str, first, second) {
  return [str.slice(0, first), str.slice(first, second), str.slice(second)];
}

function mergeStr(strArr) {
  return strArr
    .map(Number)
    .reduce((acc, cur) => acc + cur, 0)
    .toString();
}

function setAnswer(count) {
  max = Math.max(max, count);
  min = Math.min(min, count);
}

function recur(str, count) {
  const n = str.length;
  if (n >= 3) {
    for (let i = 1; i < n; i++) {
      for (let j = i + 1; j < n; j++) {
        const strs = splitThreeStr(str, i, j);
        const newStr = mergeStr(strs);
        recur(newStr, count + countOdds(newStr));
      }
    }
  } else if (n === 2) {
    const newStr = mergeStr(str.split(''));
    recur(newStr, count + countOdds(newStr));
  } else if (n === 1) {
    setAnswer(count + countOdds(input));
  }
}

function solution() {
  recur(input, 0);
  return `${min} ${max}`;
}

console.log(solution());
