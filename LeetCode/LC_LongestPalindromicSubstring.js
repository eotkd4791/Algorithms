const longestPalindrome = s => {
    let ans = '';
    const dp = JSON.parse(JSON.stringify(new Array(s.length).fill(new Array(s.length).fill(false))));

    for (let i = s.length - 1; i >= 0; i--) {
        for (let j = i; j < s.length; j++) {
            if (s.charAt(i) === s.charAt(j) && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
            }
            if (dp[i][j] && ans.length < j - i + 1) {
                ans = s.substring(i, j + 1);
            }
        }
    }
    return ans;
};