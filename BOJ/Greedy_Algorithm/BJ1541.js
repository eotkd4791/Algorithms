const input = require('fs').readFileSync('/dev/stdin').toString().trim();

const [sumFromSubtract, ...sumToSubtract] = input.split('-');

const parseNum = (str) => {
  if(typeof str === 'undefined') {
    return '';
  }
  if(str.includes('+')) {
    return str.split('+')
      .map(Number)
      .reduce((acc, cur) => acc + cur);
  } else {
    return +str;
  }  
};

console.log(parseNum(sumFromSubtract) - parseNum(sumToSubtract.join('+')));