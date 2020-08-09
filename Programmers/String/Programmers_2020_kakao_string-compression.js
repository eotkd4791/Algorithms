function solution(s) {
  let answer = s.length;
  const subLim = Math.floor(s.length / 2);

  for(let i=1; i<=subLim; i++) {
    let idx=0,
      cnt=1,
      str='',
      tmp = s.substr(idx, i);
    while(1) {
      let sub = s.substr(idx, i);

      if(idx > 0 && tmp === sub) cnt++;

      else {
        if(cnt > 1)
          str += String(cnt) + tmp;
        else if(idx !== 0)
          str += tmp;

        cnt = 1;
        tmp = sub;
      }
      if(idx >= s.length) break;
      idx += i;
    }
    answer = Math.min(str.length, answer);
  }
  return answer;
}