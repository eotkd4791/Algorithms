function solution(skill, skill_trees) {
  let answer = 0;
  let idx = 1;
  const check = {};

  for (let i of skill) {
    check[i] = idx++;
  }

  for (let v of skill_trees) {
    idx = 1;
    let flag = true;
    for (let i of v) {
      if (!check[i]) {
        continue;
      } else if (check[i] === idx) {
        idx++;
      } else {
        flag = false;
        break;
      }
    }
    if (flag) {
      answer++;
    }
  }
  return answer;
}
