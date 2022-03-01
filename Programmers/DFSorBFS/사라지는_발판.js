let n, m;
let dir = [ [0, 1], [0, -1], [-1, 0], [1, 0] ];

function isInside(x, y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

function canMove(board, x, y) {
    for(let i=0; i<4; i++) {
        let nx = x + dir[i][0];
        let ny = y + dir[i][1];
        if(isInside(nx, ny) && board[nx][ny] === 1) {
            return true;
        }
    }
    return false;
}

function recur(board, ax, ay, bx, by) {
    if(!canMove(board, ax, ay)) {
        return [false, 0];
    }
    
    const result = [false, 0];
    if(board[ax][ay] === 1) {
        let max = 0;
        let min = 987654321;
        
        for(let i=0; i<4; i++) {
            let nx = ax + dir[i][0];
            let ny = ay + dir[i][1];
            
            if(isInside(nx, ny) && board[nx][ny] === 1) {
                board[ax][ay] = 0;
                const [win, dist] = recur(board, bx, by, nx, ny);
                board[ax][ay] = 1;
                
                if(!win) {
                    result[0] = true;
                    min = Math.min(min, dist);
                } else if(!result[0]) {
                    max = Math.max(max, dist);
                }
            }   
        }
        result[1] = result[0] ? min + 1 : max + 1;
    }
    return result;
}

function solution(board, aloc, bloc) {
    n = board.length;
    m = board[0].length;
    return recur(board, aloc[0], aloc[1], bloc[0], bloc[1])[1];
}
