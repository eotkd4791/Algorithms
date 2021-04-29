/**
 * @param {string} s
 * @return {number}
 */
const myAtoi = function(s) {
  const strRemovedSpace = s.trim();
  const lowerCase = -(2 ** 31);
  const upperCase = (2 ** 31) - 1;
  let isNegative = null;
  let answer = '0';

  for(const aLetter of strRemovedSpace) {
    if((aLetter === '-' || aLetter === '+') && isNegative === null && answer.length === 1) 
      isNegative = aLetter === '-' ? true : false;
    else if('0' <= aLetter && aLetter <= '9') 
      answer += aLetter;
    else 
      break;
  }

  answer = (isNegative ? -1 : 1) * parseInt(answer);

  if(lowerCase > answer) 
    return lowerCase;
  else if(upperCase < answer) 
    return upperCase;
  else 
    return answer;
};