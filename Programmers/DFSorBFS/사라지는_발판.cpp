#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int N, M, answer;
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool is_inside(int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
}

bool can_move(vector<vector<int>> board, int x, int y) {
    for(int dir=0; dir<4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(is_inside(nx,ny) && board[nx][ny] == 1) {
            return true;
        }
    }
    return false;
}

pair<bool, int> move(vector<vector<int>> board, int ax, int ay, int bx, int by) {
    if(board[ax][ay] == 0 || !can_move(board, ax, ay)) {
        return {false, 0};
    }
    
    int MIN = 987654321;
    int MAX = 0;
    pair<bool, int> result = {false, 0};
    
    for(int dir=0; dir<4; dir++) {
        int nx = ax + dx[dir];
        int ny = ay + dy[dir];
        if(is_inside(nx,ny) && board[nx][ny] == 1) {
            board[ax][ay] = 0;
            pair<bool, int> next = move(board, bx, by, nx, ny);
            board[ax][ay] = 1;
            
            if(!next.first) {
                result.first = true;
                MIN = min(MIN, next.second);
            } else if(!result.first) {
                MAX = max(MAX, next.second);
            }
        }
    }
    result.second = result.first ? MIN + 1 : MAX + 1;
    return result;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = (int) board.size();
    M = (int) board[0].size();
    
    return move(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}
