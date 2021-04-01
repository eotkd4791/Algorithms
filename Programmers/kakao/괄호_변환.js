const getUV = str => {
  let left = 0;
  let right = 0;

  for(let i=0; i<str.length; i++) {
    str.charAt(i) === '(' 
      ? left++
      : right++;
    
    if(left && right && left === right) {
      return [
        str.slice(0, i + 1), 
        str.slice(i+1)
      ];
    }
  }
};

const isRightStr = str => {
  const stack = [];

  for(const bracket of str) {
    bracket === '('
      ? stack.push('(')
      : stack.pop();
  }
  return stack.length === 0;
};

const solution = p => {
  if(p === '') return '';

  const [ u, v ] = getUV(p);

  if(isRightStr(u)) return u + solution(v);

  return '(' + solution(v) + ')' + u.slice(1, -1).split('').map(v => v === '(' ? ')' : '(').join('');
};