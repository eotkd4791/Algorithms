const fs = require('fs');

const input = () => {
  const [NnM, ...edges] = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
  const [n, m] = NnM.split(' ').map(Number);
  const graph = edges.map((edge) => edge.split(' ').map(Number));
  return [n, m, graph];
};

const createGraph = (n, graph) => {
  const adj = JSON.parse(JSON.stringify(Array(n + 1).fill([])));
  for (const [from, to] of graph) {
    adj[from].push(to);
    adj[to].push(from);
  }
  return adj;
};

const bfs = (adj, check) => {
  const queue = [{ node: 1, dist: 0 }];
  let result = [];
  let dist = 0;
  check[1] = true;

  while (queue.length > 0) {
    const curPos = queue.pop();
    for (let i = 0; i < adj[curPos.node].length; i++) {
      const newPos = adj[curPos.node][i];

      if (!check[newPos]) {
        check[newPos] = true;
        const next = {
          node: newPos,
          dist: curPos.dist + 1,
        };
        dist = next.dist;
        queue.unshift(next);
        result.push(next);
      }
    }
  }
  result = result.filter((node) => node.dist === dist).sort((a, b) => a.node - b.node);
  return `${result[0].node} ${result[0].dist} ${result.length}`;
};

const solution = () => {
  const [n, m, graph] = input();
  const adj = createGraph(n, graph);
  return bfs(adj, Array(n + 1).fill(false));
};

console.log(solution());
