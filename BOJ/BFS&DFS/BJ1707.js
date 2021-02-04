const input = require('fs').readFileSync('/dev/stdin').toString().trim().split('\n');
const [T, ...testCase] = input;

const K = Number(T);
const tc = testCase.map(tcStr => tcStr.split(' ').map(Number));
let nextTestCase = 0;
let check;
let graph;

const BFS = (startingNode) => {
  const queue = [];
  queue.push(startingNode);

  while(queue.length > 0) {
    const curNode = queue.shift();
    const curColor = check[curNode];
    
    for(const adjNode of graph[curNode]) {
      if(check[adjNode] === 0) {
        check[adjNode] = curColor === 1 ? 2 : 1;
        queue.push(adjNode);
      } else if(check[adjNode] === curColor) {
        return false;
      }
    }
  }
  return true;
};

for(let k=0; k < K; k++) {
  const [V, E] = tc[nextTestCase];

  graph = JSON.parse(JSON.stringify(new Array(V + 1).fill([])));
  check = new Array(V + 1).fill(0);
  
  nextTestCase++;
  for(let i = nextTestCase; i < nextTestCase + E; i++) {
    const [from, to] = tc[i];
    graph[from].push(to);
    graph[to].push(from);
  }
  
  let isBipartite  = true;
  for(let i = 1; i<=V; i++) {
    if(check[i] === 0) {
      check[i] = 1;
      isBipartite = BFS(i);
      if(!isBipartite) break;
    } 
  }
  
  nextTestCase += E;
  
  if(isBipartite) console.log('YES');
  else console.log('NO');
}
