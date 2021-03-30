const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const N = +input.shift();
const field = input.map(v => v.split('').map(Number));

let answer = '';

const recur = (startX, startY, endX, endY) => {
  const initialChar = field[startX][startY];
  let isDiff = false;

  for(let i=startX; i<endX; i++) {
    for(let j=startY; j<endY; j++) {
      if(initialChar !== field[i][j]) {
        isDiff = true;
        break;
      }
    }
    if(isDiff) break;
  }

  if(isDiff) {
    const divX = Math.floor((startX + endX) / 2);
    const divY = Math.floor((startY + endY) / 2);

    answer = answer.concat('(');

    recur(startX, startY, divX, divY);
    recur(startX, divY, divX, endY);
    recur(divX, startY, endX, divY);
    recur(divX, divY, endX, endY);

    answer = answer.concat(')');
  } else {
    answer = answer.concat(initialChar);
  }
};

recur(0, 0, N, N);

console.log(answer);