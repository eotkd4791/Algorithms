#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    
    stack<int> s;
    queue<int> q[31];
    
    for(int i=0; i<board.size(); i++) {
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j] == 0) continue;
            q[j].push(board[i][j]);
        }
    }
    int answer = 0;
    
    for(int i=0; i<moves.size(); i++) {
        int idx = moves[i]-1;
        if(q[idx].empty()) continue;
        int doll = q[idx].front();
        q[idx].pop();
        
        if(s.empty()) s.push(doll);
        
        else {
            int st = (int) s.top();
            if(st == doll) {
                s.pop();
                answer+=2;
            }
            else s.push(doll);
        }
    }
    return answer;
}