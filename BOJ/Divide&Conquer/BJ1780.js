const fs = require('fs');
let [N, ...paper] = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

N = Number(N);
paper = paper.map(v => v.split(' '));

const answer = new Array(3).fill(0);

const recur = (xPos, yPos, size) => {
  let isAllSame = true;
  const initNum = paper[xPos][yPos];

  for(let i = xPos; i < xPos + size; i++) {
    for(let j = yPos; j < yPos + size; j++) {
      if(initNum !== paper[i][j]) {
        isAllSame = false;
        break;
      }
    }
    if(!isAllSame) break;
  }
  
  if(isAllSame) {
    initNum === '-1'
      ? answer[0]++
      : initNum === '0'
        ? answer[1]++
        :answer[2]++;

    return;
  }

  const divisionSize = Math.floor(size / 3);

  for(let i = xPos; i < xPos + size; i += divisionSize) {
    for(let j = yPos;  j < yPos + size; j += divisionSize) {
      recur(i, j, divisionSize);
    }
  }
};

recur(0, 0, N);

console.log(answer.join('\n'));