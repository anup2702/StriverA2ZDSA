class Solution {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        int prev = arr[0], prev2 = 0;
        for (int i = 1; i < n; i++) {
            int pick = arr[i] + prev2;
            int notPick = 0 + prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> arr1(nums.begin()+1, nums.end());
        vector<int> arr2(nums.begin(), nums.end()-1);
        int ans1 = solve(arr1);
        int ans2 = solve(arr2);
        return max(ans1, ans2);
    }
};