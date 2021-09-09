function solution(numbers, hand) {
  let answer = '';
  const mainHand = hand === 'left' ? 0 : 1;
  const thumbPos = [];
  const keypad = [
    { x: 3, y: 1, num: 0 },
    { x: 0, y: 0, num: 1 },
    { x: 0, y: 1, num: 2 },
    { x: 0, y: 2, num: 3 },
    { x: 1, y: 0, num: 4 },
    { x: 1, y: 1, num: 5 },
    { x: 1, y: 2, num: 6 },
    { x: 2, y: 0, num: 7 },
    { x: 2, y: 1, num: 8 },
    { x: 2, y: 2, num: 9 },
  ];

  numbers.forEach((number) => {
    const { x, y, num } = keypad[number];

    switch (num) {
      case 1:
      case 4:
      case 7:
        thumbPos[0] = { x, y };
        answer += 'L';
        break;
      case 3:
      case 6:
      case 9:
        thumbPos[1] = { x, y };
        answer += 'R';
        break;

      default:
        const [left, right] = thumbPos;
        const lDist = Math.abs(left.x - x) + Math.abs(left.y - y);
        const rDist = Math.abs(right.x - x) + Math.abs(right.y - y);

        if (lDist < rDist) {
          thumbPos[0] = { x, y };
          answer += 'L';
        } else if (lDist > rDist) {
          thumbPos[1] = { x, y };
          answer += 'R';
        } else {
          thumbPos[mainHand] = { x, y };
          answer += hand.slice(0, 1).toUpperCase();
        }
    }
  });
  return answer;
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], 'right'), 'LRLLLRLLRRL');
console.log(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], 'left'), 'LRLLRRLLLRR');
console.log(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], 'right'), 'LLRLLRLLRL');
