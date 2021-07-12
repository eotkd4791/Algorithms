function solution(places) {
  const answer = [];
  const dir = [ [0, 1], [0, -1], [-1, 0], [1, 0] ];

  const isInside = (x, y) => 0 <= x && x < 5 && 0 <=y && y < 5;
  const bfs = (x, y, field) => {
    const q = [];
    const visit = JSON.parse(JSON.stringify(new Array(5).fill(new Array(5).fill(false))));

    q.push({
      x, 
      y, 
      d: 0, 
      p: false
    });

    while(q.length > 0) {
      const {x, y, d, p} = q.shift();
      visit[x][y] = true;
      
      if(field[x][y] === 'P') {
        if(!p && 0 < d && d <= 2) {
          return false;
        }
      }

      dir.forEach(([dx, dy]) => {
        const nx = x + dx;
        const ny = y + dy;
        const nd = d + 1;

        if(isInside(nx, ny) && !visit[nx][ny] && nd <= 2) {
          q.push({
            x: nx,
            y: ny,
            d: d + 1,
            p: p || field[nx][ny] === 'X'
          });
        }
      });
    }
    return true;
  };
  
  places.forEach(tc => {
    let flag = false;
    for(let i=0; i<5; i++) {
      for(let j=0; j<5; j++) {
        if(tc[i][j] === 'P') {
          const result = bfs(i, j, tc);
          if(!result) {
            answer.push(0);
            flag = true;
            break;
          }
        }
      }
      if(flag) {
        break;
      }
    }
    if(!flag) {
      answer.push(1);
    }
  });
  return answer;
}