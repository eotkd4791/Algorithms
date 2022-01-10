function solution(rows, columns, queries) {
    const answer = [];
    const board = JSON.parse(
        JSON.stringify(
            Array(rows + 1).fill(
                Array(columns + 1).fill(0)
            )
        )
    );
    
    for(let i=1; i<=rows; i++) {
        for(let j=1; j<=columns; j++) {
            board[i][j] = (i-1) * columns + j;
        }
    }
    
    queries.forEach(([x1, y1, x2, y2]) => {
        const nums = [];
        for(let i=x1+1; i<=x2; i++) {
            nums.push(board[i][y1]);
        }
        for(let i=y1+1; i<=y2; i++) {
            nums.push(board[x2][i]);
        }
        for(let i=x2-1; i>=x1; i--) {
            nums.push(board[i][y2]);
        }
        for(let i=y2-1; i>=y1; i--) {
            nums.push(board[x1][i]);
        }
        
        answer.push(Math.min(...nums));
        
        let index = 0;
        for(let i=x1; i<=x2; i++) {
            board[i][y1] = nums[index++];
        }
        for(let i=y1+1; i<=y2; i++) {
            board[x2][i] = nums[index++];
        }
        for(let i=x2-1; i>=x1; i--) {
            board[i][y2] = nums[index++];
        }
        for(let i=y2-1; i>y1; i--) {
            board[x1][i] = nums[index++];
        }
    });
    return answer;
}
