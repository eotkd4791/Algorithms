function solution(answers) {    
    const first = [1,2,3,4,5];
    const second = [2,1,2,3,2,4,2,5];
    const third = [3,3,1,1,2,2,4,4,5,5];
    
    const students = [
        answers.filter((a, i) => a === first[i % first.length]).length,
        answers.filter((a, i) => a === second[i % second.length]).length,
        answers.filter((a, i) => a === third[i % third.length]).length
    ];
    
    const max = Math.max(...students);
    
    return students.reduce((acc, cur, index) => 
        cur === max
            ? acc.concat(index + 1)
            : acc, []);
}
