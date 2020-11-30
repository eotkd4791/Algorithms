const solution = gems => {
  const gemSet = new Set(gems);
  const gemMap = new Map();
  const gemArr = [];

  gems.forEach((v, i) => {
    gemMap.delete(v);
    gemMap.set(v, i);
    
    if(gemMap.size === gemSet.size) {
      gemArr.push([gemMap.values().next().value + 1, i + 1]);
    }
  });
  
  gemArr.sort((a, b) => {
    if(a[1] - a[0] < b[1] - b[0]) return -1;
    if(a[0] < b[0]) return -1;
    return 1;
  });

  return gemArr[0];
}