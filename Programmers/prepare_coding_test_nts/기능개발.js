function solution(progresses, speeds) {
    const answer = [];
    const restDays = [];
    const n = progresses.length;
    const checkedDays = Array(n).fill(false);
    
    for(let i=0; i<n; i++) {
        const restWork = 100 - progresses[i];
        const restDay = Math.ceil(restWork / speeds[i]);
        restDays.push(restDay);
    }
    
    while(checkedDays.includes(false)) {
        let count = 0;
        for(let i=0; i<n; i++) {
            if(!checkedDays[i]) {
                if(restDays[i] <= 0) {
                    checkedDays[i] = true;
                    count++;
                } else {
                    break;
                }
            }
        }
        if(count > 0) {
            answer.push(count);    
        }
        for(let i=0; i<n; i++) {
            restDays[i]--; 
        }
    }   
    return answer;
}
