// memoization
class Solution {
public:
    int fn(int idx, int prev, vector<int>& nums, vector<vector<int>>& memo, int n){
        if(idx == n) return 0;
        if(memo[idx][prev+1] != -1) return memo[idx][prev+1];
        int len = fn(idx+1, prev, nums, memo, n);
        if(prev == -1 or nums[idx] > nums[prev]) len = max(len,1 + fn(idx+1, idx, nums, memo, n));
        return memo[idx][prev+1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n+1, -1));
        return fn(0, -1, nums, memo, n);
    }
};

// tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int idx=n-1; idx>=0; idx--){
            for(int prev=idx-1; prev>=-1; prev--){
                int len = dp[idx+1][prev+1];
                if(prev == -1 or nums[idx] > nums[prev]) len = max(len, 1+ dp[idx+1][idx+1]);
                dp[idx][prev+1] = len;
            }
        }
        return dp[0][-1+1];
    }
};

// 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i] > nums[j]) d[i] = max(d[i], d[j]+1);
            }
        }
        return *max_element(d.begin(), d.end());
    }
};


// binary search - nlogn
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1; i<n; i++){
            if(nums[i] > temp.back()) temp.push_back(nums[i]);
            else{
                int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[idx] = nums[i];
            }
        }
        return temp.size();
    }
};