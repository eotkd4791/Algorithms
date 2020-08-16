const pre = [], post = [];

class Node {
  constructor(index, cur, left, right) {
    this.index = index + 1;
    this.cur = cur;
    this.left = left;
    this.right = right;
  }
}

function tree(node, list) {
  pre.push(node.index);
  const left = list.filter(v => node.cur[1] > v.cur[1] && node.cur[0] > v.cur[0]);
  const right = list.filter(v => node.cur[1] > v.cur[1] && node.cur[0] < v.cur[0]);

  if (left.length > 0) {
    node.left = left[0];
    tree(left[0], left);
  }
  if (right.length > 0) {
    node.right = right[0];
    tree(right[0], right);
  }
  post.push(node.index);
}

function solution(nodeinfo) {
  const oNode = [...nodeinfo];
  
  oNode.sort((a, b) => {
    if (a[1] > b[1]) return -1;
    else if (a[1] === b[1]) return a[0] < b[0] ? -1 : 1;
    else return 1;
  });
  const nodeList = oNode.map(v => new Node(nodeinfo.indexOf(v), v, false, false));
  tree(nodeList[0], nodeList);
  return [pre, post];
}
