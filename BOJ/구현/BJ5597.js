const fs = require('fs');

function solution() {
  let submit = init();
  getInput().forEach((input) => {
    submit ^= 1 << input;
  });
  return getAnswer(submit);
}

function getInput() {
  return fs.readFileSync('/dev/stdin').toString().trim().split('\n').map(Number);
}

function init() {
  let submit = 0;
  for (let i = 1; i <= 30; i++) {
    submit |= 1 << i;
  }
  return submit;
}

function getAnswer(submit) {
  let result = '';
  for (let i = 1; i <= 30; i++) {
    const absent = submit & (1 << i);
    if (absent) {
      result += i.toString() + '\n';
    }
  }
  return result;
}

console.log(solution());
