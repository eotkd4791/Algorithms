const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');

const [size, ...field] = input;
const [N, M] = size.split(' ').map(Number);
const queue=[];
const dx = [1, -1, 0, 0];
const dy = [0, 0, -1, 1];


const distFromStart = JSON.parse(JSON.stringify(
  new Array(2).fill(
    new Array(N).fill(
      new Array(M).fill(0)
    )
  )
));

const isInBorder = (x, y) => (0 <= x && x < N && M > y && y >= 0);

const bfs = (x, y, breakCnt) => {
  queue.push({
    x, 
    y,
    breakCnt, 
  });
  distFromStart[1][x][y] = 1;

  while(queue.length > 0) {
    const {x, y, breakCnt} = queue.shift();

    if(x === N - 1 && y === M - 1) {
      return distFromStart[breakCnt][x][y];
    }

    for(let dir = 0; dir < 4; dir++) {
      const newXPos = x + dx[dir];
      const newYPos =  y + dy[dir];
      
      if(isInBorder(newXPos, newYPos)) {
        if(field[newXPos][newYPos] === '0' && distFromStart[breakCnt][newXPos][newYPos] === 0) {
          queue.push({
            x: newXPos, 
            y: newYPos, 
            breakCnt, 
          });
          distFromStart[breakCnt][newXPos][newYPos] = distFromStart[breakCnt][x][y] + 1;
        } 
        if(field[newXPos][newYPos] === '1' && breakCnt > 0 &&  distFromStart[breakCnt][newXPos][newYPos] === 0) {
          queue.push({
            x: newXPos,
            y: newYPos,
            breakCnt: 0,
          });
          distFromStart[breakCnt - 1][newXPos][newYPos] = distFromStart[breakCnt][x][y] + 1;
        }
      }
    }
  }
  return -1;
};

console.log(bfs(0,0,1));