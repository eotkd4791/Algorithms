function solution(n, times) {
  const arr = times.sort();
  let ans = 0,
    l = 1,
    r = arr[times.length - 1] * n;

  while (l <= r) {
    let m = Math.floor((l + r) / 2);
    let sum = 0;

    for (let i of arr) {
      sum += Math.floor(m / i);
    }

    if (sum >= n) {
      r = m - 1;
      ans = m;
    } else {
      l = m + 1;
    }
  }
  return ans;
}
