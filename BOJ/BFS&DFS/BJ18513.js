const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
let [_, k] = input[0].split(' ').map(Number);

class Queue {
  #size = 0;
  #head = null;
  #cur = null;

  size() {
    return this.#size;
  }

  push(arg) {
    const newData = { data: arg, next: null };
    if(this.#head === null) {
      this.#head = newData;
      this.#cur = this.#head;
    } else {
      this.#cur.next = newData;
      this.#cur = newData;
    }
    this.#size++;
  }

  pop() {
    if(this.empty()) {
      return;
    } 
    const nodeWillBeDeleted = this.#head;
    this.#head = nodeWillBeDeleted.next;
    this.#size--;
    return nodeWillBeDeleted.data;
  }

  empty() {
    return this.#size === 0;
  }
}

const init = () => {
  const wells = input[1].split(' ').map(Number);
  const queue = new Queue();
  const visit = {};
  wells.forEach(well => {
    queue.push({ pos: well, dist: 0 });
    visit[well] = true;
  });
  return { queue, visit };
};

const bfs = (queue, visit) => {
  let answer = 0;
  const dir = [ -1, 1 ];
  
  while(!queue.empty()) {
    const { pos, dist } = queue.pop();

    for(let d = 0; d < dir.length; d++) {
      const newPos = pos + dir[d];
      if(!visit.hasOwnProperty(newPos)) {
        visit[newPos] = true;
        queue.push({ pos: newPos, dist: dist + 1 });
        answer += dist + 1;
        k--;
        if(k === 0) {
          return answer;
        }
      }
    }
  }
  return answer;
};

(() => {
  const { queue, visit } = init();
  console.log(bfs(queue, visit));
})();