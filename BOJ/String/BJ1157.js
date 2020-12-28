const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().toUpperCase();

const map = new Map();
let MAX = -Infinity;

for(let i=0; i<input.length; i++) {
  if(map.has(input[i])) {
    const currentValue = map.get(input[i]);
    map.set(input[i], currentValue + 1);
    MAX = Math.max(MAX, currentValue + 1);
  } else {
    map.set(input[i], 1);
    MAX = Math.max(MAX, 1);
  }
}

let compareValue = null;
const mValues = map.values();
const mKeys = map.keys();

while(1) {
  const nextValue = mValues.next();
  const nextKey = mKeys.next();

  if(nextValue.value === MAX) {
    if(compareValue) {
      console.log('?');
      break;
    } else {
      compareValue = nextKey.value;
    }
  }

  if(nextValue.done) {
    console.log(compareValue);
    break;
  }
}