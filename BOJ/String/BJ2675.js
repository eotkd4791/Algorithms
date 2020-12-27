const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const testCase = input.slice(1).map(v => v.split(' '));

testCase.forEach(strArray => {
  const [repeatCount, targetString] = strArray;
  const repeatCountToNumber = Number(repeatCount);

  let resultString='';

  for(let i=0; i<targetString.length; i++) {
    for(let j=0; j<repeatCountToNumber; j++) {
      resultString += targetString[i];
    }
  }
  
  console.log(resultString);
});