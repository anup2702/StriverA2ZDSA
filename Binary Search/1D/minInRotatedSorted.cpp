class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r= nums.size()-1;
        if(nums[l] < nums[r]) return nums[l];
        int ans = INT_MAX;
        while(l <= r){
                int m = l + (r-l)/2;
                if(nums[m] >= nums[l]){
                    ans = min(ans, nums[l]);
                    l = m + 1;
                }
                else {
                    ans = min(ans, nums[m]);
                    r = m - 1;
                }
        }
        return ans;
    }
};