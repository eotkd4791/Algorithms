let MAX, row, col, rel;

function isUnique(num) {
  const s = new Set();

  for (let i = 0; i < row; i++) {
    let str = '';
    for (let j = 0; j < col; j++) if (num & (1 << j)) str += rel[i][col-j-1];
    if (str !== '') s.add(str);
  }
  return s.size === rel.length;
}

function comp(num) {
  return num.toString(2)
            .split('')
            .filter(v => v === '1')
            .length;
}

function solution(relation) {
  const candidateKey = [];

  rel = [...relation];
  row = relation.length;
  col = relation[0].length;
  MAX = Math.pow(2, col);
  for (let i = 1; i < MAX; i++) if (isUnique(i)) candidateKey.push(i);


  candidateKey.sort((a, b) => comp(a) - comp(b));

  const check = new Array(candidateKey.length).fill(true);
  for (let i = 0; i < candidateKey.length; i++) {
    if (!check[i]) continue;
    for (let j = i+1; j < candidateKey.length; j++) 
      if((candidateKey[i] & candidateKey[j]) === candidateKey[i]) 
        check[j] = false;
  }
  return check.filter((v, i) => check[i]).length;
}
