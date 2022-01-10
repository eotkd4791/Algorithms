function solution(n, edge) {
    const graph = JSON.parse(JSON.stringify(Array(n+1).fill([])));
    edge.forEach(([from, to]) => {
        graph[from].push(to);
        graph[to].push(from);
    });
    
    const q = [];
    const visit = Array(n+1).fill(false);
    const dist = Array(n+1).fill(0);
    
    q.push(1);
    visit[1] = true;
    
    while(q.length > 0) {
        const cur = q.shift();
        
        const len = graph[cur].length;
        for(let i=0; i<len; i++) {
            const next = graph[cur][i];
            if(!visit[next]) {
                visit[next] = true;
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }
    const max = Math.max(...dist);
    return dist.filter(d => d === max).length;
}
