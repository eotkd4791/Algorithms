let check,
  arr,
  row,
  col,
  oList = [];

function isValid(nList) {
  const s = new Set();

  arr.forEach(v => {
    let str = "";
    for (let i of nList) {
      str += v[i];
    }
    s.add(str);
  });
  return s.size === row;
}

function recur(idx, nList) {
  const newOne = nList.toString().split(",").join("");
  if (nList.length > 0 && isValid(nList)) {
    oList.push(newOne);
  }
  for (let i = idx; i < col; i++) {
    if (!check[i]) {
      check[i] = true;
      recur(i + 1, [...nList, i]);
      check[i] = false;
    }
  }
}

function solution(rel) {
  row = rel.length;
  col = rel[0].length;

  arr = [...rel];
  check = new Array(col).fill(false);
  recur(0, []);

  oList.sort((a, b) => {
    if (a.length < b.length) return -1;
    else if (a.length === b.length) return Number(a) > Number(b) ? -1 : 1;
    else return 1;
  });

  let cKeyCheck = new Array(oList.length).fill(true);

  for (let i = 0; i < oList.length; i++) {
    if (!cKeyCheck[i]) continue;
    for (let k = 0; k < oList.length; k++) {
      let cnt = oList[i].length;
      if (i === k) continue;
      for (let j = 0; j < oList[i].length; j++) {
        for (let l = 0; l < oList[k].length; l++) {
          if (oList[i][j] === oList[k][l]) cnt--;
        }
      }
      if (cnt === 0) cKeyCheck[k] = false;
    }
  }
  oList.forEach((v, i) => {
    console.log(v, cKeyCheck[i]);
  });
  return oList.filter((v, i) => cKeyCheck[i]).length;
}
