const input = require('fs').readFileSync('/dev/stdin').toString().trim().split(' ');
const [x, y, w, h] = input.map(Number);

console.log(
  Math.min(
    Math.abs(x-0),
    Math.abs(y-0),
    Math.abs(x-w),
    Math.abs(y-h),
  )
);