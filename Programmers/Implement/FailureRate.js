function solution(N, stages) {
    let answer = [];
    const arr = stages.sort(),
        atStage = new Array(N).fill(0),
        fail = [];
    
    arr.forEach(v => {
        atStage[v-1]++;
    });
    
    let len = stages.length;
    let people= 0;
    
    for(let i=0; i<N; i++) {
        if(len-people===0) {
            continue;
        }
        fail.push({
            idx: i+1,
            val: atStage[i]/(len-people)
        });
        people += atStage[i];
    }
    
    answer = fail.sort((a,b) => {
        if(a.val > b.val) {
            return -1;    
        } else if(a.val===b.val) {
            if(a.idx < b.idx) {
                return -1;
            }
            return 1;
        }
        return 1;
    }).map(v=> v.idx);
    
    let fl = fail.length;
    while(fl!==N) {
        answer.push(++fl);
    }
    
    return answer;
}
