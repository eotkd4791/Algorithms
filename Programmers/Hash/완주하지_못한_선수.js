function solution(participant, completion) {
    const p = {};
    participant.forEach(v => {
        if(v in p) {
            p[v]++;
        } else {
            p[v] = 1;
        }
    });

    completion.forEach(v => {
       p[v]--;
    });

    for(const key in p) {
        if(p[key] > 0) {
            return key;
        }
    }
}
