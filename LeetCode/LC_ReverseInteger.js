const reverse = x => {
  const xStr = x.toString();

  let xArr = xStr.split('').reverse();
  let isMinus = false;
  let isOutOfRange = false;

  if(xArr.length === 1) return x;

  if(xArr[xArr.length - 1] === '-') {
    isMinus = true;
    xArr.pop();
  }

  if(xArr[0] === '0') {
    xArr = xArr.splice(1);
  }

  const resStr = xArr.join('');
  const result = isMinus ? '-'.concat(resStr) : resStr;
  isOutOfRange = (Number(result) > -(1 << 31) - 1) || (Number(result) < (1 << 31));

  return isOutOfRange ? 0 : result;
};
