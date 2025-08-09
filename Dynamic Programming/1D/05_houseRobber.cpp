class Solution {
public:
    /*  Memoization
        int fn(int i, vector<int>& nums, vector<int>& dp) {
            if (i == 0) return nums[i];
            if (i < 0) return 0;
            if(dp[i] != -1) return dp[i];
            int pick = nums[i] + fn(i - 2, nums, dp);
            int notPick = 0 + fn(i - 1, nums, dp);
            return dp[i] = max(pick, notPick);
        }

        int rob(vector<int>& nums) {
            int n = nums.size();
            vector<int> dp(n, -1);
            return fn(n - 1, nums, dp);
        }
    */

    /* Tablulation
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + ((i > 1) ? dp[i - 2] : 0);
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
    */

    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0], prev2 = 0;
        for (int i = 1; i < n; i++) {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};