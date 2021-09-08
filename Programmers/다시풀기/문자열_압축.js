function solution(s) {
  let answer = s.length;

  for (let cnt = 1; cnt <= s.length / 2; cnt++) {
    let prevStr = s.slice(0, cnt);
    let index = 0;
    let repeatCnt = 1;
    let result = '';

    while (index < s.length) {
      index += cnt;
      const nextStr = s.slice(index, index + cnt);
      if (prevStr === nextStr) {
        repeatCnt++;
      } else {
        result += `${repeatCnt > 1 ? repeatCnt : ''}${prevStr}`;
        repeatCnt = 1;
        prevStr = nextStr;
      }
    }
    answer = Math.min(answer, result.length);
  }
  return answer;
}

// console.log(solution('aabbaccc'));
console.log(solution('ababcdcdababcdcd'));
// console.log(solution('abcabcdede'));
// console.log(solution('abcabcabcabcdededededede'));
// console.log(solution('xababcdcdababcdcd'));
