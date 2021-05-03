/**
 * @param {number} num
 * @return {string}
 */
const intToRoman = function(num) {
    let answer = '';
    const ints = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1];
    const roms = ['M', 'CM', 'D','CD', 'C','XC','L','XL','X','IX','V','IV','I'];
    
    let digit = num;
    let index = 0;
    while(digit > 0) {
        let div = Math.floor(digit/ints[index]);
        if(div > 0) {
            while(div--) answer += roms[index];
            digit %= ints[index];
        }
        index++;
    }
    return answer;
};