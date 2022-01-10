function solution(board, moves) {
    let answer = 0;
    const stack = [];
    
    moves.forEach(move => {
       const row = move - 1;
        for(let i=0; i<board.length; i++) {
            if(board[i][row] > 0) {
                const dollType = board[i][row];
                board[i][row] = 0;
                if(stack.length > 0) {
                    if(dollType === stack[stack.length-1]) {
                        stack.pop();
                        answer += 2;
                        break;
                    }
                }
                stack.push(dollType);
                break;
            }  
        }
    });
    return answer;
}
