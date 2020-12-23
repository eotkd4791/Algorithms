const reverse = x => {
  let isMinus = false;

  if(x < 0) {
    x *= -1;
    isMinus = true;
  }
  
  const reverseStr = x.toString().split('').reverse().join('');
  const reverseNum = Number(isMinus ? '-'.concat(reverseStr) : reverseStr);

  if((2 ** 31) - 1 < reverseNum || (-2) ** 31 > reverseNum) {
    return 0;
  }

  return reverseNum;
};