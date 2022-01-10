function solution(N, number) {
    let answer = -1;
    let dp = Array(9).fill().map(() => new Set());
    
    for(let i=1; i<=8; i++) {
        dp[i].add(Number(N.toString().repeat(i)));
        for(let j=1; j<i; j++) {
            for(const val1 of dp[j]) {
                for(const val2 of dp[i-j]) {
                    dp[i].add(val1 + val2);
                    dp[i].add(val1 - val2);
                    dp[i].add(val1 * val2);
                    dp[i].add(val1 / val2);
                }
            }
        }
        if(dp[i].has(number)) {
            answer = i;
            break;
        }
    }
    return answer;
}
