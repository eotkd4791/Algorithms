/**
 * @param {string[][]} places
 * @returns {number[]}
 */
function solution(places) {
  let answer = [];
  const dx = [0, 0, 1, -1];
  const dy = [1, -1, 0, 0];

  for (const place of places) {
    let flag = false;
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        if (place[i][j] === 'P') {
          if (!bfs(i, j, place)) {
            flag = true;
            break;
          }
        }
      }
      if (flag) {
        answer.push(0);
        break;
      }
    }
    if (!flag) {
      answer.push(1);
    }
  }
  return answer;

  function isInside(x, y) {
    return 0 <= x && x < 5 && 0 <= y && y < 5;
  }

  function bfs(sx, sy, place) {
    const queue = [{ x: sx, y: sy, partitionExist: false, dist: 0 }];
    const visit = JSON.parse(JSON.stringify(Array(5).fill(Array(5).fill(false))));

    while (queue.length > 0) {
      const { x, y, dist, partitionExist } = queue.shift();
      visit[x][y] = true;

      if (place[x][y] === 'P') {
        if (0 < dist && dist <= 2 && !partitionExist) {
          return false;
        }
      }

      for (let dir = 0; dir < 4; dir++) {
        const nx = x + dx[dir];
        const ny = y + dy[dir];

        if (isInside(nx, ny) && !visit[nx][ny] && dist < 3) {
          queue.push({
            x: nx,
            y: ny,
            partitionExist: partitionExist || place[nx][ny] === 'X',
            dist: dist + 1
          });
        }
      }
    }
    return true;
  }
}
