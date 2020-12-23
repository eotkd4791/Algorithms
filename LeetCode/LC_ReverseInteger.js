const reverse = x => {
  const reverseStr = (x < 0 ? (-x) : x).toString().split('').reverse().join('');
  const reverseNum = Number(isMinus ? '-'.concat(reverseStr) : reverseStr);

  return  (2 ** 31) - 1 < reverseNum || (-2) ** 31 > reverseNum ? 0 : reverseNum;
};

