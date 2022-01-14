/**
 *
 * @param {string} s
 * @returns {number}
 *
 * ? 문제 설명
 * 반복되는 문자열 압축하기
 * 반복되는 숫자 + 문자열 형식으로 압축했을 때 가장 많이 압축된(짧은) 문자열의 길이 구하기
 *
 * ! 주의할 점, 제약사항
 * i) 문자열 길이 최대 1000 : O(n^2) 가능한 시간 -> 백만(10^6)
 * ii) 다른 길이로 자를 수 없음. 예시 5번 참고
 *
 * * 문제 풀이
 * 1부터 문자열 길이 / 2까지의 숫자에 대해 탐색.
 * 문자열 길이의 최소값을 return
 */
function solution(s) {
  const n = s.length;
  const halfLength = Math.floor(n / 2);
  let answer = n;

  for (let ci = 1; ci <= halfLength; ci++) {
    let tempStr = '';
    let repeatCount = 1;
    let standardStr = '';
    let compareStr = '';
    for (let si = 0; si < n; si += ci) {
      standardStr = s.substr(si, ci);
      compareStr = s.substr(si + ci, ci);
      if (standardStr === compareStr) {
        repeatCount++;
      } else if (repeatCount > 1) {
        tempStr += repeatCount + standardStr;
        repeatCount = 1;
      } else {
        tempStr += standardStr;
      }
    }
    if (repeatCount > 1) {
      tempStr += repeatCount + standardStr;
    }
    answer = Math.min(answer, tempStr.length);
  }
  return answer;
}
