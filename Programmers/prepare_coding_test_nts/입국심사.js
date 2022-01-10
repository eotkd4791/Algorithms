function solution(n, times) {
    times.sort((a, b) => a - b);
    
    let answer = 0;
    let left = 1;
    let right = times[times.length - 1] * n;
    
    while(left <= right) {
        const mid = Math.floor((left + right) / 2);
        let sum = 0;
        
        for(const time of times) {
            sum += Math.floor(mid / time);
        }
        if(sum >= n) {
            right = mid - 1;
            answer = mid;
        } else {
            left = mid + 1;
        }
    }
    return answer;
}
