const solution = gems => {
  const gemKinds = new Set(gems).size;

  if(gemKinds === 1) return [1, 1];
  if(gemKinds === gems.length) return [1, gems.length];
    
  let start = 0;
  let end = gems.length;
  let ans = [];

  while(start <= end) {
    const mid = Math.floor((start + end) / 2);
    const [left, right] = search(gems, gemKinds, mid);

    if(left + 1 || right + 1) {
      end = mid - 1;
      ans = [left + 1, right + 1];
      if(ans[0] === 1 && ans[1] === 1) break;
    } else {
      start = mid + 1;
    }
  }
  return ans;
}

const search = (gems, gemKinds, mid) => {
  const map = new Map();
  
  for(let i = 0; i < mid; i++) {
    if(map.has(gems[i])) {
      const newVal = map.get(gems[i]) + 1;
      map.set(gems[i], newVal);
    } else {
      map.set(gems[i], 1);
    }
  }
  
  let left = 0;
  let right = mid - 1;

  if(map.size === gemKinds) {
    return [left, right];
  }

  while(right + 1 < gems.length) {
    if(map.get(gems[left]) === 1) {
      map.delete(gems[left]);
    } else {
      const newVal = map.get(gems[left]) - 1;
      map.set(gems[left], newVal);
    }

    if(map.has(gems[right + 1])) {
      const newVal = map.get(gems[right + 1]) + 1;
      map.set(gems[right + 1], newVal);
    } else {
      map.set(gems[right + 1], 1);
    }

    left++; right++;

    if(map.size === gemKinds) {
      return [left, right];
    }
  }
  return [];
}
