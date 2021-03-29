const fs = require('fs');
const input = fs.readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const N = +input.shift();
const paper = input.map(v => v.split(' ').map(Number));

let whiteCnt = 0;
let blueCnt = 0;

const recur = (leftTopX, leftTopY, rightBottomX, rightBottomY) => {
  let whiteTempCnt = 0;
  let blueTempCnt = 0;

  for(let i=leftTopX; i<rightBottomX; i++) {
    for(let j=leftTopY; j<rightBottomY; j++) {
      paper[i][j] === 0
        ? whiteTempCnt++
        : blueTempCnt++;
    }
  }

  if(whiteTempCnt > 0 && blueTempCnt > 0) {
    recur(
      leftTopX, 
      leftTopY, 
      Math.floor((leftTopX + rightBottomX) / 2), 
      Math.floor((leftTopY + rightBottomY) / 2)
    );

    recur(
      leftTopX, 
      Math.floor((leftTopY + rightBottomY) / 2), 
      Math.floor((leftTopX + rightBottomX) / 2), 
      rightBottomY
    );

    recur(
      Math.floor((leftTopX + rightBottomX) / 2), 
      leftTopY, 
      rightBottomX, 
      Math.floor((leftTopY + rightBottomY) / 2)
    );

    recur(
      Math.floor((leftTopX + rightBottomX) / 2), 
      Math.floor((leftTopY + rightBottomY) / 2), 
      rightBottomX, 
      rightBottomY
    );
  } else {
    whiteTempCnt > 0 && whiteCnt++;
    blueTempCnt > 0 && blueCnt++;
  }
};

recur(0, 0, N, N);
console.log(`${whiteCnt}\n${blueCnt}`);