const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();

function solution() {
  let result = '';
  const letter = new Array(26).fill(0);
  countLetters();
  createPalindrome();
  return checkIfPalindrome();

  function letterToIndex(a) {
    return a.charCodeAt() - 65;
  }

  function convertNumToStr(num) {
    return String.fromCharCode(num + 65);
  }

  function countLetters() {
    for (const a of input) {
      letter[letterToIndex(a)]++;
    }
  }

  function concatBetween(str) {
    const half = result.length / 2;
    return result.slice(0, half) + str + result.slice(half);
  }

  function createPalindrome() {
    letter.forEach((l, i) => {
      const cnt = l - (l % 2);
      const str = convertNumToStr(i);
      result = concatBetween(str.repeat(cnt));
      letter[i] = l % 2;
    });
  }

  function checkIfPalindrome() {
    const rest = letter.reduce((acc, cur) => acc + cur, 0);
    if (rest === 1) {
      const index = letter.findIndex((l) => l > 0);
      return concatBetween(convertNumToStr(index));
    } else if (rest > 1) {
      return `I'm Sorry Hansoo`;
    } else {
      return result;
    }
  }
}

console.log(solution());
