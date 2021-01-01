const fs = require('fs');
const [A, B ,C] = fs.readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);

if(B>=C) console.log(-1);
else console.log(Math.floor(A/(C-B)) + 1);