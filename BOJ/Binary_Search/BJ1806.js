const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [N, S, ...arr] = input[0].split(' ').concat(input[1].split(' ')).map(Number);

const getSum = (target) => {
  let tempArr = arr.slice(0, target);
  let sum = tempArr.reduce((acc,cur) => acc + cur, 0);

  if(sum >= S) return true;

  for(let i=target; i<N; i++) {
    sum -= arr[i-target];
    sum += arr[i];
    if(sum>=S) return true;
  }
  return false;
};

const binarySearch = (end) => {
  let left = 0;
  let right = end;
  let answer = 0;

  while(left <= right) {
    const mid = Math.floor((left + right) / 2);
    if(getSum(mid)) {
      right = mid - 1;
      answer = mid;
    }
    else {
      left = mid + 1;
    }
  }
  return answer;
};

console.log(binarySearch(N));