function solution(orders, course) {
  const cnt = Array(27).fill(0);
  const um = {};
  const menu = JSON.parse(JSON.stringify(new Array(27).fill(new Array(21).fill([]))));

  const answer = [];

  orders.forEach((order) => {
    const orderedStr = order.split('').sort().join('');
    recur(orderedStr, 0, '');
  });

  for (const i of course) {
    if (cnt[i] > 1) {
      for (const s of menu[i][cnt[i]]) {
        answer.push(s);
      }
    }
  }

  return answer.sort();

  function recur(s, idx, made) {
    if (made.length > 1) {
      made in um ? um[made]++ : (um[made] = 1);
      cnt[made.length] = Math.max(cnt[made.length], um[made]);
      menu[made.length][um[made]].push(made);
    }

    for (let i = idx; i < s.length; i++) {
      recur(s, i + 1, made + s[i]);
    }
  }
}

console.log(solution(['ABCFG', 'AC', 'CDE', 'ACDE', 'BCFG', 'ACDEH'], [2, 3, 4]));
