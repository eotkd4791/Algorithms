const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const [N, M, ...graph] = input;
const V = Number(N);
const E = Number(M);

const parent = new Array(V + 1).fill(1).map((v, i) => i);

const find = node => {
  if(node === parent[node]) return node;
  return parent[node] = find(parent[node]);
};

const merge = (nodeA, nodeB) => {
  const pNodeA = find(nodeA);
  const pNodeB = find(nodeB);

  if(pNodeA === 1) {
    parent[pNodeB] = pNodeA;
  } else {
    parent[pNodeA] = pNodeB;
  }

  for(let i=1; i<=V; i++) find(i);
};

for(let i=0; i<E; i++) {
  const [from, to] = graph[i].split(' ').map(Number);
  
  merge(from, to);
}

console.log(parent.filter(v => v === 1).length - 1);