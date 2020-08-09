function solution(n, arr1, arr2) {
  const arr = arr1.map((v, i) => (v | arr2[i]).toString(2));
  const answer = [];

  arr.forEach(v => {
    let str = '';
    while(str.length + v.length < n) str +=' ';
    for(let i=0; i<v.length; i++)
      str += v[i] === '1' ? '#' : ' ';
    answer. push(str);
  });
  return answer;
}