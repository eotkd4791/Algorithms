let answer = 0;
const map = new Map();

function isPrime(str) {
  const toNum = Number(str);
  if(map.has(toNum.toString())) return false;
  if(toNum <= 1) return false;

  const sqrtToNum = Math.sqrt(toNum);
  
  for(let i=2; i<=sqrtToNum; i++) {
    if(toNum % i===0) return false;
  }
  map.set(toNum.toString(), true)
  return true;
}

function recur(str, cur, arr, check) {
  if(str.length >= 1) {
    console.log(str)
    if(isPrime(str)) answer++;
  }
  for(let i=0; i<arr.length; i++) {
    if(check[i]) continue;
    check[i] = true;
    recur(str + arr[i], i, arr, check);
    check[i] = false;
  }
}

function solution(numbers) {
  let arr = numbers.split('');
  const check = new Array(arr.length).fill(false);

  recur('', 0, arr, check);
  
  return answer;
}

console.log(solution('011'))