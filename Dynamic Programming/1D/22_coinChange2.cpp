class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<double> dp(amount + 1, 0);
        dp[0] = 1;

        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return (int)(dp[amount] + 0.1); // round off minor floating errors
    }
};