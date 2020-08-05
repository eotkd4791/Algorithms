function solution(lines) {
  let ans = 0;
  const arr = [];

  lines.forEach(v => {
    const date = v.split(" ");
    const time = date[1].split(":");
    const mil = parseFloat(date[2].substr(0, date[2].length - 1)) * 1000;

    let s = 3600;
    let sec = 0;
    time.forEach(t => {
      sec += parseFloat(t) * s * 1000;
      s /= 60;
    });
    arr.push([sec - mil + 1, sec]);
  });

  arr.sort((a, b) => (a[0] < b[0] ? -1 : 1));

  const pq = [];
  let time = arr[0][0];

  for (let v of arr) {
    if (time + 999 < v[0]) {
      while (pq[0] + 999 < v[0] && pq.length > 0) {
        pq.shift();
      }
      time = pq.length === 0 ? v[0] : pq[0];
    }
    const newIdx = pq.findIndex(i => i > v[1]);
    pq.splice(newIdx === -1 ? pq.length : newIdx, 0, v[1]);
    ans = Math.max(ans, pq.length);
  }
  return ans;
}
