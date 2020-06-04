#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<vector<int> > v(35);
int arr[11], horse[4], score[35], ans;
bool check[35];
const int START = 0, FINISH = 32, FIRST = 5, SECOND = 10, THIRD = 15;

//이동할 수 있는지  판단하는 함수

void createGraph() {
    int tmp=2;
    for(int i=0; i<20; i++) {
        v[i].push_back(i+1);
        score[i+1]=tmp;
        tmp+=2;
    }
    tmp=13;
    v[5].push_back(21);
    score[21] = tmp;
    tmp+=3;
    for(int i=21; i<23; i++) {
        v[i].push_back(i+1);
        score[i+1] = tmp;
        tmp+=3;
    }
    v[23].push_back(29);
    score[29]=25;
    
    tmp=22;
    v[10].push_back(24);
    score[24]=tmp;
    tmp+=2;
    v[24].push_back(25);
    score[25] = tmp;
    v[25].push_back(29);
    score[29] = 25;
    
    tmp=28;
    v[15].push_back(26);
    score[26] = tmp;
    for(int i=26; i<29; i++){
        v[i].push_back(i+1);
        score[i+1] = --tmp;
    }
    
    tmp=30;
    for(int i=29; i<31; i++) {
        v[i].push_back(i+1);
        score[i+1] = tmp;
        tmp+=5;
    }
    v[31].push_back(20);
    v[20].push_back(32);
    score[20] = 40;
    score[32] = 0;
}

void recur(int ordIdx, int sum) {
    
    if(ordIdx == 10) {
        ans = ans < sum ? sum : ans;
        return;
    }
    
    for(int i=0; i<4; i++) {
        if(horse[i] == FINISH) continue;
        int curNode = horse[i];
        int idx = 0;
        if(curNode == FIRST || curNode == SECOND || curNode == THIRD) idx = 1;
        int newNode = curNode;
        bool isArrived = false;
        for(int j=0; j < arr[ordIdx]; j++) {
            if(newNode == FINISH) {
                isArrived = true;
                break;
            }
            newNode = v[newNode][idx];
            idx=0;
        }
        if(isArrived) {
            check[curNode] = false;
            horse[i] = FINISH;
            recur(ordIdx+1, sum);
            check[curNode] = true;
            horse[i] = curNode;
            continue;
        }
        if(!check[newNode]) {
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
    for(int i=0; i<10; i++) cin >> arr[i];
    createGraph();
    recur(0, 0);
    cout << ans << '\n';
    return 0;
}

