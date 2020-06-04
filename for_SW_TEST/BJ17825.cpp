#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > v(35);
int arr[11], horse[4], score[35], ans;
bool check[35];
const int FIRST = 5, SECOND = 10, THIRD = 15,  FINISH = 32;

/* 윷판 그리는 함수. <인접 리스트>
--------------------------- */
void createGraph() {
    int tmp = 0;
    for(int i = 0; i < 20; i++) {
        tmp += 2; v[i].push_back(i + 1); score[i + 1] = tmp;
    }
    
    
    tmp = 13; v[5].push_back(21); score[21] = tmp;
    for(int i = 21; i < 23; i++) {
        tmp += 3; v[i].push_back(i + 1); score[i + 1] = tmp;
    }
    v[23].push_back(29); score[29] = 25;
    
    
    tmp = 22; v[10].push_back(24); score[24] = tmp;
    tmp += 2; v[24].push_back(25); score[25] = tmp;
    v[25].push_back(29); score[29] = 25;
    
    
    tmp = 28; v[15].push_back(26); score[26] = tmp;
    for(int i = 26; i < 29; i++){
        v[i].push_back(i + 1); score[i + 1] = --tmp;
    }
    
    
    for(int i = 29; i < 31; i++) {
        tmp += 5; v[i].push_back(i + 1); score[i + 1] = tmp;
    }
    v[31].push_back(20); score[20] = 40;
    v[20].push_back(32); score[32] = 0;
}

void recur(int ordIdx, int sum) {
    if(ordIdx == 10) {
        ans = ans < sum ? sum : ans;
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(horse[i] == FINISH) continue; // 이미 도착해있는 말은 재낌.
        
        int curNode = horse[i], idx = 0;
        
        if(curNode == FIRST || curNode == SECOND || curNode == THIRD) idx = 1; // 교차 가능한 노드에서는 벡터의 두번째 인덱스[1]로 이동시킨다.
        int newNode = curNode;
        
        bool isArrived = false;
        for(int j = 0; j < arr[ordIdx]; j++) { // 주사위로 이동하기.
            if(newNode == FINISH) { // 이동 중, 도착하면 이동을 멈추고, 점수를 더하지 않는다.
                isArrived = true;
                break;
            }
            newNode = v[newNode][idx];
            idx=0;
        }
        if(isArrived) { // 이번 턴에서 도착지점에 도착할 경우 이 부분으로 들어감.
            check[curNode] = false;
            horse[i] = FINISH;
            recur(ordIdx + 1, sum);
            check[curNode] = true;
            horse[i] = curNode;
        }
        else if(!check[newNode]) { // 이동하려는 위치에 다른 말이 있다면 다른 말을 선택한다.
            check[curNode] = false;
            check[newNode] = true;
            horse[i] = newNode;
            recur(ordIdx + 1, sum + score[newNode]);
            horse[i] = curNode;
            check[curNode] = true;
            check[newNode] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 10; i++) cin >> arr[i];
    createGraph();
    recur(0, 0);
    cout << ans << '\n';
    return 0;
}