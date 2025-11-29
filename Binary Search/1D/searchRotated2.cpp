class Solution {
public:
    bool search(vector<int>& nums, int target) {
       int l = 0, r = nums.size()-1;
       while(l <= r){
            int m = l + (r - l)/2;
            if(nums[m] == target) return true;
            if(nums[l] == nums[m] and nums[m] == nums[r]){
                l++; r--;
            }
            else if(nums[l] <= nums[m]){
                if(nums[l] <= target and target < nums[m]) r = m -1;
                else l = m + 1;
            } else{
                if(nums[m] < target and target <= nums[r]) l = m + 1;
                else r = m - 1;
            }
       } 
       return false;
    }
};