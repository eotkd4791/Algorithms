///////////////////////////////
/*
   Programmers Remove_Min
                             */
///////////////////////////////
#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    if(arr.size()==1) {
        answer.push_back(-1);
        return answer;
    }
    int MIN=arr[0];
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]<MIN)
            MIN=arr[i];
    }
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==MIN) continue;
        answer.push_back(arr[i]);
    }
    return answer;
}
