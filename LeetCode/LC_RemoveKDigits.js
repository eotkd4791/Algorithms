/**
 * @param {string} num
 * @param {number} k
 * @return {string}
 */
const removeKdigits = function(num, k) {
  const s = [num[0]];
  for(let i=1; i<num.length; i++) {
    while(s.length > 0 && s[s.length - 1] > num[i] && k > 0) {
      s.pop();
      k--;
    }
    if(!(s.length === 0 && num[i] === '0')) s.push(num[i]);
  }
  while(s.length>0 && k>0) {
    s.pop();
    k--;
  }
  const result = s.join('');
  return s.length === 0 ? '0' : result;
};