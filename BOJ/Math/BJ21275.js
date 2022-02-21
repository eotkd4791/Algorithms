const fs = require('fs');
const [numByA, numByB] = fs.readFileSync('/dev/stdin').toString().trim().split(' ');

function solution() {
  let answer = '';
  let answerCount = 0;

  for (let i = 2; i <= 36; i++) {
    const tempXByA = parseInt(numByA, i);
    for (let j = 2; j <= 36; j++) {
      if (i === j) continue;
      const tempXByB = parseInt(numByB, j);
      if (tempXByA === tempXByB) {
        answerCount++;
        answer = `${tempXByA} ${i} ${j}`;
      }
    }
  }

  if (answerCount === 0) {
    return 'Impossible';
  } else if (answerCount === 1) {
    return answer;
  } else {
    return 'Multiple';
  }
}

console.log(solution());
