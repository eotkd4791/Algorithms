const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, M, ...edges] = input;
const V = Number(N);
const E = Number(M);
const network = JSON.parse(JSON.stringify(new Array(V + 1).fill([])));
const infectedComputers = new Set();

const dfs = cur => {
  infectedComputers.add(cur);

  for(const computer of network[cur]) {
    if(infectedComputers.has(computer)) continue;
    dfs(computer);
  }
};

for(let i=0; i<E; i++) {
  const [from, to] = edges[i].split(' ').map(Number);
  
  network[from].push(to);
  network[to].push(from);
}

dfs(1);
console.log(infectedComputers.size - 1);