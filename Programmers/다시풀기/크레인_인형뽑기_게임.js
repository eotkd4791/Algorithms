function solution(board, moves) {
  let answer = 0;
  const pickedDolls = [];
  const n = board.length;

  moves.forEach((move) => {
    const colIndex = move - 1;
    let rowIndex = 0;

    while (rowIndex < n && board[rowIndex][colIndex] === 0) {
      rowIndex++;
    }

    if (rowIndex < n) {
      const pickedDoll = board[rowIndex][colIndex];
      board[rowIndex][colIndex] = 0;

      if (pickedDolls.length > 0 && pickedDolls[pickedDolls.length - 1] === pickedDoll) {
        pickedDolls.pop();
        answer += 2;
      } else {
        pickedDolls.push(pickedDoll);
      }
    }
  });
  return answer;
}

console.log(
  solution(
    [
      [0, 0, 0, 0, 0],
      [0, 0, 1, 0, 3],
      [0, 2, 5, 0, 1],
      [4, 2, 4, 4, 2],
      [3, 5, 1, 3, 1],
    ],
    [1, 5, 3, 5, 1, 2, 1, 4]
  )
);
