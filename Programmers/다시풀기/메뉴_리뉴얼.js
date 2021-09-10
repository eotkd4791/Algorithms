function solution(orders, course) {
  let answer = [];
  const visit = {};
  const cnt = {};
  const check = Array(27).fill(false);
  const temp = Array(27).fill([]);

  orders.forEach((order) => {
    const orderedStr = order.split('').sort().join('');
    recur(orderedStr, 0, '');
  });

  for (const orderComb in visit) {
    if (visit[orderComb] > 1) {
      const n = orderComb.length;
      if (n in cnt) {
        if (cnt[n] < visit[orderComb]) {
          cnt[n] = visit[orderComb];
          temp[n] = [orderComb];
        } else if (cnt[n] === visit[orderComb]) {
          temp[n].push(orderComb);
        }
      } else {
        cnt[n] = visit[orderComb];
        temp[n] = [orderComb];
      }
    }
  }

  return [
    ...new Set(course.reduce((acc, crs) => acc.concat(temp[crs]), []).map((ans) => ans.split('').sort().join(''))),
  ].sort();

  function recur(order, index, str) {
    if (str.length > 1) {
      visit[str] = str in visit ? visit[str] + 1 : 1;
    }

    for (let i = index; i < order.length; i++) {
      const charIndex = order[i].charCodeAt() - 65;
      if (!check[charIndex]) {
        check[charIndex] = true;
        recur(order, index + 1, str + order[i]);
        check[charIndex] = false;
      }
    }
  }
}

console.log(solution(['ABCFG', 'AC', 'CDE', 'ACDE', 'BCFG', 'ACDEH'], [2, 3, 4]));
console.log(solution(['ABCDE', 'ABCDE', 'ACD', 'ACD', 'AD', 'AD'], [2, 3, 4]));
