function solution(n) {
    let answer = '';
    
    while(n > 0) {
        answer = '412'.charAt(n % 3) + answer;    
        n = Math.floor((n - 1) / 3);
    }
    
    return answer;
}
