function lengthOfLongestSubstring(s) {
  let left = 0;
  let right = s.length;
  let ans = 0;
  
  while(left <= right) {
    const mid = Math.floor((left + right) / 2);

    if(isOk(mid, s)) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return ans;
}

function isOk(mid, s) {
  const check = {};
  let left = 0;
  let right = mid - 1;

  for(let i=0; i<mid; i++) {
    s[i] in check
      ? check[s[i]] += 1
      : check[s[i]] = 1; 
  }
  if(Object.keys(check).length === mid) return true;

  while(right + 1 < s.length) {
    check[s[left]] === 1
      ? delete check[s[left]]
      : check[s[left]] -= 1;

    s[right + 1] in check
      ? check[s[right+1]] += 1
      : check[s[right+1]] = 1;

    left++; right++;

    if(Object.keys(check).length === mid) return true;
  }
  return false;
}