function countPS(s) {
    const n = s.length;
    const dp = Array.from(Array(n), () => Array(n).fill(0));

    // Every single character is a palindrome
    for (let i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the table for substrings of length greater than 1
    for (let length = 2; length <= n; length++) {
        for (let i = 0; i <= n - length; i++) {
            const j = i + length - 1;
            if (s[i] === s[j]) {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }

    return dp[0][n - 1];
}

// Driver code
const s = "geeksforgeeks"; 
console.log(countPS(s));