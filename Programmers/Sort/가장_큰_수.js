function solution(numbers) {
  const answer = numbers
    .sort((a, b) => {
      const aFirst = a.toString() + b.toString();
      const bFirst = b.toString() + a.toString();
      return aFirst > bFirst ? -1 : 1;
    })
    .join('');
    
  return Number(answer) === 0 ? "0" : answer;
}