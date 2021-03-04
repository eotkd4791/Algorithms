const input = require('fs')
  .readFileSync('/dev/stdin')
  .toString()
  .split('\n')
  .map(cur => cur.split(' ').map(Number));

const dp = JSON.parse(JSON.stringify(
  new Array(21)
    .fill(new Array(21)
      .fill(new Array(21)
        .fill(0)
      )
    )
  )
);

const w = (aa,bb,cc) => {
  if(aa <= 0 || bb <= 0 || cc <= 0) return 1;
  
  if(aa > 20 || bb > 20 || cc > 20) return w(20, 20, 20);
  
  if(dp[aa][bb][cc] > 0) return dp[aa][bb][cc];

  if(aa < bb && bb < cc) 
    dp[aa][bb][cc] = w(aa, bb, cc -1) + w(aa, bb-1, cc-1) - w(aa, bb-1, cc);
  else
    dp[aa][bb][cc] = w(aa - 1, bb, cc) + w(aa - 1, bb - 1, cc) + w(aa - 1, bb, cc - 1) - w(aa - 1, bb - 1, cc - 1);
  
  return dp[aa][bb][cc];
};

for(let i=0; i<input.length; i++) {
  const [a, b, c] = input[i];
  if(a === -1 && b === -1 && c === -1) break;
  console.log(`w(${a}, ${b}, ${c}) = ${w(a, b, c)}`);
};