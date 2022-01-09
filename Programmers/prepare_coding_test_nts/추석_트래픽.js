function solution(lines) {
    let answer = 0;
    
    const times = lines.map(line => {
        const [D, S, T] = line.split(' ');
        const mili = Date.parse(`${D} ${S}`);
        const processTime = Number(T.slice(0, -1)) * 1000;
        return [mili - processTime + 1, mili + 1000];
    })
    
    const n = times.length;
    for(let i=0; i<n; i++) {
        let count = 0;
        for(let j=i; j<n; j++) {
            if(times[i][1] > times[j][0]) {
                count++;
            }
        }
        answer = Math.max(answer, count);
    }
    return answer;
}
