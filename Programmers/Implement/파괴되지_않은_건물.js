function solution(board, skill) {
    const DESTROY = 1;
    let answer = 0;
    const n = board.length;
    const m = board[0].length;
    const building = JSON.parse(
        JSON.stringify(
            Array(n+2).fill(
                Array(m+2).fill(0)
            )
        )
    );
    
    for(let [type, r1, c1, r2, c2, deg] of skill) {
        if(type === DESTROY) {
            deg = -deg;
        }
        building[r1+1][c1+1] += deg;
        building[r2+2][c1+1] -= deg;
        building[r1+1][c2+2] -= deg;
        building[r2+2][c2+2] += deg;
    }
    
    for(let i=1; i<=n; i++) {
        for(let j=1; j<=m; j++) {
            building[i][j] = building[i][j] + building[i-1][j] + building[i][j-1] - building[i-1][j-1];
            board[i-1][j-1] += building[i][j];
            if(board[i-1][j-1] >= 1) {
                answer++;
            }
        }
    }
    return answer;
}
