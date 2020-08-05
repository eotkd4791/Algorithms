function solution(lines) {
  let ans = 0;
  const time = lines.map(v => {
    const mil = Date.parse(`${v.split(" ")[0]} ${v.split(" ")[1]}`);
    const diff = v.split(" ")[2].split("s")[0] * 1000;
    return [mil - diff + 1, mil];
  });

  for (let i of time) {
    const cnt = [0, 0];
    for (let j of time) {
      if (j[0] - 999 <= i[0] && i[0] <= j[1]) cnt[0]++;
      if (j[0] - 999 <= i[1] && i[1] <= j[1]) cnt[1]++;
    }
    ans = Math.max(ans, ...cnt);
  }
  return ans;
}
