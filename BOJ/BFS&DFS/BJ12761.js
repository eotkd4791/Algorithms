const fs = require('fs');
const [A, B, N, M] = fs.readFileSync('/dev/stdin').toString().trim().split(' ').map(Number);

class Node {
  constructor(val, next = null) {
    this.val = val;
    this.next = next;
  }
}
class Queue {
  head = null;
  cur = null;
  size = 0;

  push(val) {
    if (this.head) {
      this.cur.next = new Node(val);
      this.cur = this.cur.next;
    } else {
      this.cur = new Node(val);
      this.head = this.cur;
    }
    this.size++;
  }
  pop() {
    if (!this.head) {
      return null;
    }
    const nodeToPop = this.head.val;
    this.head = this.head.next;

    this.size--;
    return nodeToPop;
  }
  empty() {
    return this.size === 0;
  }
}

const INF = 100_000;
const isInside = (x) => 0 <= x && x <= INF;
const direction = (type, cur) => {
  const dir = [1, -1, -1 * A, A, -1 * B, B];
  if (0 <= type && type < 6) {
    return cur + dir[type];
  } else if (type === 6) {
    return cur * A;
  } else {
    return cur * B;
  }
};

function solution() {
  const dp = Array(INF + 1).fill(0);
  const visit = Array(INF + 1).fill(false);
  const q = new Queue();

  q.push(N);
  visit[N] = true;

  while (!q.empty()) {
    const currentPosition = q.pop();

    for (let i = 0; i < 8; i++) {
      const newPosition = direction(i, currentPosition);
      if (!visit[newPosition] && isInside(newPosition)) {
        q.push(newPosition);
        visit[newPosition] = true;
        dp[newPosition] = dp[currentPosition] + 1;
      }
    }
  }
  console.log(dp[M]);
}

solution();
