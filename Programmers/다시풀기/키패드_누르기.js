function solution(numbers, hand) {
  const mainHand = hand === 'left' ? 0 : 1;
  const thumbPos = [
    { x: 3, y: 0 },
    { x: 3, y: 2 },
  ];
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

  return numbers
    .map((number) => {
      const { x, y, num } = keypad[number];

      if (/[147]/.test(num)) {
        return moveLeftThumb(x, y);
      } else if (/[369]/.test(num)) {
        return moveRightThumb(x, y);
      }

      const [left, right] = thumbPos;
      const lDist = Math.abs(left.x - x) + Math.abs(left.y - y);
      const rDist = Math.abs(right.x - x) + Math.abs(right.y - y);

      if (lDist < rDist) {
        return moveLeftThumb(x, y);
      } else if (lDist > rDist) {
        return moveRightThumb(x, y);
      } else {
        thumbPos[mainHand] = { x, y };
        return hand[0].toUpperCase();
      }
    })
    .join('');

  function moveLeftThumb(x, y) {
    thumbPos[0] = { x, y };
    return 'L';
  }
  function moveRightThumb(x, y) {
    thumbPos[1] = { x, y };
    return 'R';
  }
}

console.log(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], 'right') === 'LRLLLRLLRRL');
console.log(solution([7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2], 'left') === 'LRLLRRLLLRR');
console.log(solution([1, 2, 3, 4, 5, 6, 7, 8, 9, 0], 'right') === 'LLRLLRLLRL');
