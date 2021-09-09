function solution(s) {
  let answer = s;
  const letters = ['zero', 'one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine'];
  letters.forEach((letter, index) => (answer = answer.split(letter).join(index.toString())));
  return Number(answer);
}

console.log(solution('one4seveneight'));
