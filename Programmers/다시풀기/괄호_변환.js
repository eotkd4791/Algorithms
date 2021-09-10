function solution(p) {
  return recur(p);

  function recur(str) {
    if (str === '') {
      return str;
    }
    const [u, v] = splitUV(str);
    if (isCorrect(u)) {
      return u + recur(v);
    } else {
      return '(' + recur(v) + ')' + flipBrackets(removeSideBrackets(u));
    }
  }

  function splitUV(str) {
    let acc = '';
    let i;
    for (i = 0; i < str.length; i++) {
      if (isBalanced(acc)) {
        break;
      }
      acc += str[i];
    }
    return [acc, str.slice(i)];
  }

  function isBalanced(str) {
    let l = 0;
    let r = 0;
    for (const s of str) {
      s === '(' ? l++ : r++;
    }
    return l > 0 && l === r;
  }

  function isCorrect(str) {
    const stack = [];
    for (const s of str) {
      if (s === '(') {
        stack.push(s);
      } else {
        if (stack.length === 0) {
          return false;
        }
        stack.pop();
      }
    }
    return stack.length === 0;
  }

  function removeSideBrackets(str) {
    return str.slice(1, -1);
  }

  function flipBrackets(str) {
    let result = '';
    for (const s of str) {
      result += s === '(' ? ')' : '(';
    }
    return result;
  }
}

console.log(solution('()))((()') === '()(())()');
console.log(solution(')(') === '()');
console.log(solution('(()())()') === '(()())()');
