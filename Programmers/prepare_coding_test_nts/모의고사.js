function solution(answers) {
    const first = [1,2,3,4,5];
    const second = [2,1,2,3,2,4,2,5];
    const third = [3,3,1,1,2,2,4,4,5,5];
    
    const firstUserAnswerCount = computeAnswerCount(first);
    const secondUserAnswerCount = computeAnswerCount(second); 
    const thirdUserAnswerCount = computeAnswerCount(third);
    const maxScore = Math.max(
        firstUserAnswerCount,
        secondUserAnswerCount,
        thirdUserAnswerCount
    );
    
    return [
        firstUserAnswerCount, 
        secondUserAnswerCount, 
        thirdUserAnswerCount
    ].map((count, index) => ({ user: index + 1, count }))
     .filter(({ user, count }) => count === maxScore)
     .map(({ user }) => user);
    
    function computeAnswerCount(arr) {
        let countMatchedAnswer = 0;
        answers.forEach((a, i) => {
            if(a === arr[i % arr.length]) {
                countMatchedAnswer++;
            }
        });
        return countMatchedAnswer;
    }
}
