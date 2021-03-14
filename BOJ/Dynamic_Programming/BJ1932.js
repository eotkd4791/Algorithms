const fs = require('fs');
const input = fs
  .readFileSync('/dev/stdin')
  .toString()
  .trim()
  .split('\n');

const N = Number(input.shift());
const tri = input.map(v => {
  const top = Number(v);
  if(Number.isNaN(top)) {
    return v.split(' ').map(Number);
  } 
  return [top];
});

const dp = JSON.parse(JSON.stringify(new Array(N).fill([])));

const recur = (i, j) => {
  if(i === N-1) return tri[i][j];
  if(typeof dp[i][j] !== 'undefined') return dp[i][j];  
  return dp[i][j] = Math.max(recur(i+1, j), recur(i+1, j+1)) + tri[i][j];
};

console.log(recur(0,0));