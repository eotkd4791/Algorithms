function solution(s) {
  let answer = '';
  const numbers = {
      zero: 0,
      one: 1,
      two: 2,
      three: 3,
      four: 4,
      five: 5,
      six: 6,
      seven: 7,
      eight: 8,
      nine: 9
  };
  
  let tempStr = '';
  for(let i=0; i<s.length; i++) {
      tempStr += s[i];
      if(numbers.hasOwnProperty(tempStr)) {
          answer += numbers[tempStr];
          tempStr = '';
      } else if(/[0-9]/.test(tempStr)) {
          answer += tempStr;
          tempStr = '';
      }
  } 
  return parseInt(answer);
}