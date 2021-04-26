/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
const convert = function(s, numRows) {
  if(numRows === 1) return s;
  let cnt = 0;
  let dir = 1;
  const arr = JSON.parse(JSON.stringify(new Array(numRows).fill([])));

  for(const str of s) {
    if(!outOfBorder(cnt)) {
        dir *= (-1);
        cnt += dir * 2;
    }
    arr[cnt].push(str);
    cnt += dir;
  }
  return arr.reduce((acc, cur) => acc += cur.join(''),'');

  function outOfBorder(row) {
    return 0 <= row && row < numRows;
  }
};