function solution(priorities, location) {
    const queue = priorities.map((priority, index) => ({ p: priority, l:  index }));
    let answer = 0;
    
    while(true) {
        const { p, l } = queue[0];
        const temp = queue.find(print => print.p > p);
        if(temp) {
            queue.push(queue.shift());
        } else {
            answer++;
            if(queue.shift().l === location) {
                return answer;
            }
        }
    }
}
