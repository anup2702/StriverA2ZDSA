class Solution {
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        bool dp[n+1][target+1];
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=target; j++){
                if(j==0) dp[i][j] = true;
                else if(i==0) dp[i][j] = false;
                else if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++) sum += nums[i];
        if(sum % 2 != 0) return false;
        return isSubsetSum(nums, sum/2);
    }
};