const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().split('\n');

const [cnt, ...edgeStr] = input;
const [N, M, V] = cnt.split(' ').map(Number);
const edges = edgeStr.map(v => v.split(' ').map(Number));

const graph = JSON.parse(JSON.stringify(new Array(N + 1).fill([])));
let s = new Set();
let result = [];

for(let i=0; i<M; i++) {
  const [start, end] = edges[i];
  
  graph[start].push(end);
  graph[end].push(start);
};

graph.forEach(v => {
  v.sort((a, b) => a - b);
});

function dfs(cur) {
  s.add(cur);

  result.push(cur);

  for(const next of graph[cur] || []) {
    if(s.has(next)) continue; 
    dfs(next);
  }
}

function bfs (start) {
  const queue = [];
  queue.push(start);

  while(queue.length > 0) {
    const cur = queue.shift();
    result.push(cur);

    for(const next of graph[cur] || []) {
      if(s.has(next)) continue;
      s.add(next);
      queue.push(next);
    }
  };
}

dfs(V);
console.log(result.join(' '));
s = new Set([V]);
result = [];
bfs(V);
console.log(result.join(' '));