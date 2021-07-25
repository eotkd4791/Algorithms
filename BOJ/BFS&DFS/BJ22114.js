const fs = require('fs');

const input = () => {
  const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  const [n, k] = input[0].split(' ').map(Number);
  const l = input[1].split(' ').map(Number);
  return { n, k, l };
};

const main = () => {
  const { n, k, l } = input();

  let left = 0;
  let right = 0;
  let jumped = false;
  let answer = 0;

  while(right < n) {
    if(l[right] <= k) {
      right++;
      answer = Math.max(answer, right - left + 1);
    } else {
      if(jumped) {
        answer = Math.max(answer, right - left + 1);

        while(l[left] <= k) {
          left++;
        }
        left++;
        jumped = false;
      } else {
        jumped = true;
        right++;
      }
    }
  }
  return answer;
};

console.log(main());