function solution(new_id) {
  let answer = '';

  const onlyLowerCase = new_id.toLowerCase();
  const removedSymbols = onlyLowerCase.split(/[^\.|\-|_|a-z|0-9]/g).join('');
  const removeRepeatedDots = removedSymbols.split(/\.+/g).join('.');
  const removeSideDots = trimDot(removeRepeatedDots);
  const trimOverLetterLength = trimDot((removeSideDots.length === 0 ? 'a' : removeSideDots).slice(0, 15));

  answer = trimOverLetterLength;
  while (answer.length <= 2) {
    answer += trimOverLetterLength.slice(-1);
  }

  return answer;

  function trimDot(str) {
    const removeDotsFirst = str[0] === '.' ? str.slice(1) : str;
    const removeDotsLast = removeDotsFirst.slice(-1) === '.' ? removeDotsFirst.slice(0, -1) : removeDotsFirst;
    return removeDotsLast;
  }
}

// console.log(solution('...!@BaT#*..y.abcdefghijklm'));
// console.log(solution('=.='));
// console.log(solution('123_.def'));
console.log(solution('-_.~!@#$%^&*()=+[{]}:?,<>/'));
