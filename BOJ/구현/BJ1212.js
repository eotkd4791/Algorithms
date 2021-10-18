const fs = require('fs');

const getInput = () => fs.readFileSync('/dev/stdin').toString().trim();

const solution = () => {
  const nStr = getInput();
  const oCnt = nStr.length;
  let result = '';

  for (let i = 0; i < oCnt; i++) {
    const decimal = +nStr[i];
    const binary = decimal.toString(2);

    result += i > 0 && binary.length < 3 ? '0'.repeat(3 - binary.length) + binary : binary;
  }
  return result;
};

console.log(solution());
