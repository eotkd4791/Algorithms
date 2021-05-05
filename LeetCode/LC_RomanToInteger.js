/**
 * @param {string} s
 * @return {number}
 */
const romanToInt = function(s) {
  let answer = 0;
  let latest = 0;
  const map = { I: 1, V: 5, X: 10, L: 50  ,C: 100, D: 500, M: 1000 };
  for(let i=s.length - 1; i>=0; i--) {
    latest <= map[s[i]]
      ? answer += map[s[i]]
      : answer -= map[s[i]];
    latest = map[s[i]];
  }
  return answer;
};