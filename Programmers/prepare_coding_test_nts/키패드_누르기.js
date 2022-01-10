function solution(numbers, hand) {
    let answer = '';
    let left = 10;
    let right = 11;
    
    const keypad = [
        [3, 1],
        [0, 0], [0, 1],[0, 2],
        [1, 0], [1, 1],[1, 2],
        [2, 0], [2, 1],[2, 2],
        [3, 0], [3, 2]
    ];
    
    numbers.forEach(number => {
       if([1, 4, 7].includes(number)) {
           left = number;
           answer += 'L';
       } else if([2, 5, 8, 0].includes(number)) {
           const [tx, ty] = keypad[number];
           const [lx, ly] = keypad[left];
           const [rx, ry] = keypad[right];
           const distFromLeft = Math.abs(tx - lx) + Math.abs(ty - ly);
           const distFromRight = Math.abs(tx - rx) + Math.abs(ty - ry);
           
           if(distFromLeft < distFromRight) {
               left = number;
               answer += 'L';
           } else if(distFromLeft > distFromRight) {
               right = number;
               answer += 'R';
           } else {
               if(hand === 'left') {
                   left = number;
                   answer += 'L';
               } else {
                   right = number;
                   answer += 'R';
               }
           }
       } else if([3, 6, 9].includes(number)) {
           right = number;
           answer += 'R';
       }
    });
    
    return answer;
}
