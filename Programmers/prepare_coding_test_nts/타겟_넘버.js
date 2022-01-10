function solution(numbers, target) {
    const n = numbers.length;
    let answer = 0;
    dfs(0, 0, 0);
    return answer;
    
    function dfs(index, cnt, sum) {
        if(cnt === n) {
            sum === target && answer++;
            return;
        }
        
        dfs(index + 1, cnt + 1, sum + numbers[index]);
        dfs(index + 1, cnt + 1, sum - numbers[index]);
    }
}
