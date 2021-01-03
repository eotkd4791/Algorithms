const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim();
const num = Number(input);

const arr = new Array(21).fill(0);

function fib(n) {
  if(arr[n] > 0) return arr[n];
  if(n === 0) return 0;
  if(n <= 2) return 1;

  return arr[n] = fib(n-2) + fib(n-1);
}
console.log(fib(num));
